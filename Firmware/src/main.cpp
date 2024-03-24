/*********************导入库*************************/
#include "main.h"
#include "wificonfig.h"
#include "touchbutton.h"
#include "task.h"


String data_app;
BluetoothSerial SerialBT;
int threshold = 40;

TaskHandle_t Task0_Handle;
TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t Task3_Handle;

// 创建触摸按键中断信号量
SemaphoreHandle_t touch1Semaphore= xSemaphoreCreateBinary();
SemaphoreHandle_t touch2Semaphore= xSemaphoreCreateBinary();
SemaphoreHandle_t touch3Semaphore= xSemaphoreCreateBinary();







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
        setClock();
    }else{
        Serial.println();
        Serial.println("wifi连接失败请使用蓝牙配网");
        //WiFi.disconnect(true);
    }
    //触摸中断
    touchAttachInterrupt(T0, gotTouch1, threshold);



    //任务
    xTaskCreate(timeDisplay, "timeTask",  2048    , NULL, 2, &Task0_Handle);

    xTaskCreate(Touch1Task, "Task1",  2048    , NULL, 1, &Task1_Handle);

   //xTaskCreate(Touch2Task, "Task2",  2048    , NULL, 2, &Task2_Handle);
    
    //xTaskCreate(Touch3Task, "Task3",  2048    , NULL, 2, &Task3_Handle);

}
/**********************自循环************************/
void loop() {
  //bluetooth();

}