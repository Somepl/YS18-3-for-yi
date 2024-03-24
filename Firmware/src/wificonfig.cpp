#include"wificonfig.h"

//****************初始化联网*************************
bool init_wifi(){
    int count = 0;
    WiFi.begin();
    while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
    count++;
    if (count==20){
    return false;}}
    return true;
}



/***********************蓝牙*************************/
void bluetooth() { //接收蓝牙数据

    if (Serial.available()) {               //用于调试
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available()){
        data_app = "";
        data_app = SerialBT.readString();
        Serial.print("接收数据为：");        //用于调试
        Serial.println(data_app);           //用于调试
        if (data_app=="ip_mac"){
            String ip_mac = ipmac();
            SerialBT.println(ip_mac);
            Serial.println(ip_mac);
        }
        else if(data_app.indexOf("ssid")!=-1){
            StaticJsonDocument<200> doc;
            DeserializationError error = deserializeJson(doc, data_app);
            if (error) {
                Serial.println("数据格式错误");  //用于调试
                SerialBT.print("Incorrect format of incoming data");
            }
            else {
                String sid = doc["ssid"];
                String pwd = doc["password"];
                if (sid!="null"){
                    Serial.printf("SSID:%s\r\n",sid); //用于调试
                    if (pwd=="null"){
                        pwd = "";
                        }
                    Serial.printf("PAWD:%s\r\n",pwd); //用于调试
                    if(wifiPW(sid,pwd)){
                        SerialBT.println("True");
                    }else{
                        SerialBT.println("False");
                    }
                }
                else {
                    Serial.println("未识别到wifi数据"); //用于调试
                    SerialBT.print("Incorrect format of incoming data");
                }
            }
        }
        else{
            Serial.println("未接收到指令"); //用于调试
            SerialBT.print("Incorrect format of incoming data");
        }
    }
}
bool wifiPW(String sid,String pwd){//配网
    WiFi.begin(sid.c_str(), pwd.c_str());
    int count = 0;
    delay(1000);
    while (WiFi.status()!=WL_CONNECTED){
        Serial.print(".");
        delay(500);
        count++;
        if (count>20){
          Serial.println();
          Serial.println("配网失败");
          return false;}
    }
    Serial.println();
    Serial.println("配网成功");
    return true;
}
String ipmac(){//获取ip、mac地址
    if(WiFi.isConnected()){
        String ip = WiFi.localIP().toString();
        String mac = WiFi.macAddress();
        return "{'ip':'"+ip+"','mac':'"+mac+"'}";
    }else{
        return "Not connected to wifi";
    }
}
/****************************************************/