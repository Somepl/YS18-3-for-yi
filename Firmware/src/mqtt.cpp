// #include "mqtt.h"



// const char* mqttServer = "123.206.103.210";
// const int mqttPort = 1883;
// const char* mqttUser = "123";
// const char* mqttPassword = "321";
// const char* mqttTopic = "test";


// WiFiClient espClient;
// PubSubClient client(espClient);


// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message arrived [");
//   Serial.print(topic);   // 打印主题信息
//   Serial.print("] ");
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]); // 打印主题内容
//   }
//   Serial.println();
 
// //   if ((char)payload[0] == '1') {
// //     digitalWrite(LED_BUILTIN, HIGH);   // 亮灯
// //   } else {
// //     digitalWrite(LED_BUILTIN, LOW);   // 熄灯
// //   }


//   // 处理接收到的消息
// }



// void setup() {
  





//   client.setServer(mqttServer, mqttPort);
//   client.setCallback(callback);

//   while (!client.connected()) {
//     Serial.println("Connecting to MQTT Broker...");
//     if (client.connect("mqttx_605d3dfb", mqttUser, mqttPassword)) {
//       Serial.println("Connected to MQTT Broker");
//       client.subscribe(mqttTopic);
//     } else {
//       Serial.print("Failed to connect to MQTT Broker. Retrying in 5 seconds...");
//       delay(5000);
//     }
//   }
// }

// void loop() {

//   client.loop();

// }
