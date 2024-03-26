/*********************导入库*************************/
#include "main.h"
#include "wificonfig.h"
#include "touchbutton.h"
#include "task.h"
#include "weather.h"


String data_app;
BluetoothSerial SerialBT;
/*********************MQTT*************************/
WiFiClient espClient;
PubSubClient client(espClient);
const char* mqttServer = "123.206.103.210";
const int mqttPort = 1883;
const char* mqttUser = "123";
const char* mqttPassword = "321";
const char* mqttTopic = "test";

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);   // 打印主题信息
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]); // 打印主题内容
  }
  Serial.println();
//   if ((char)payload[0] == '1') {
//     digitalWrite(LED_BUILTIN, HIGH);   // 亮灯
//   } else {
//     digitalWrite(LED_BUILTIN, LOW);   // 熄灯
//   }
  // 处理接收到的消息
}
/*********************MQTT*************************/
int threshold = 40;

TaskHandle_t Task0_Handle;
TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t Task3_Handle;

// 创建触摸按键中断信号量
SemaphoreHandle_t touch1Semaphore= xSemaphoreCreateBinary();
SemaphoreHandle_t touch2Semaphore= xSemaphoreCreateBinary();
SemaphoreHandle_t touch3Semaphore= xSemaphoreCreateBinary();

SemaphoreHandle_t MutexSemaphore1=xSemaphoreCreateMutex();
SemaphoreHandle_t MutexSemaphore2=xSemaphoreCreateMutex();
SemaphoreHandle_t MutexSemaphore3=xSemaphoreCreateMutex();






/**********************初始值************************/
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

/**********************初始化*************************/
void setup() {
    Serial.begin(115200);
    WiFi.hostname("myESP32");
    SerialBT.begin("myESP32");
    Serial.println("现在可进行蓝牙配对!这是新的");
    if(init_wifi()){
        Serial.println();
        Serial.println("wifi连接成功");
        WiFi.config(WiFi.localIP(), WiFi.gatewayIP(), WiFi.subnetMask(),{119, 29, 29, 29}, {223, 5, 5, 5});
        setClock();
    }else{
        Serial.println();
        Serial.println("wifi连接失败请使用蓝牙配网");
        //WiFi.disconnect(true);
    }

    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    for(int i=0;i<5;i++) {
        Serial.println("Connecting to MQTT Broker...");
        if (client.connect("mqttx_605d3dfb", mqttUser, mqttPassword)) {
            Serial.println("Connected to MQTT Broker");
            client.subscribe(mqttTopic);
        } else {
        Serial.print("Failed to connect to MQTT Broker. Retrying in 5 seconds...");
        delay(5000);
        }
    }

    //触摸中断
    touchAttachInterrupt(T0, gotTouch1, threshold);
    touchAttachInterrupt(T4, gotTouch2, threshold);
    //touchAttachInterrupt(T3, gotTouch3, threshold);

    //任务
    xTaskCreate(timeDisplay, "timeTask",  2048    , NULL, 2, &Task0_Handle);

    xTaskCreate(Touch1Task, "Task1wificonfig",  2048    , NULL, 2, &Task1_Handle);

    xTaskCreate(Touch2Task, "Task2weather",  4096    , NULL, 2, &Task2_Handle);
    
    xTaskCreate(Touch3Task, "Task3mqtt",  2048    , NULL, 2, &Task3_Handle);

}
/**********************自循环************************/
void loop() {

}