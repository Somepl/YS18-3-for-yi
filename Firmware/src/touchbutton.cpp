#include "touchbutton.h"






void gotTouch1(){
  // 获取当前时间
  unsigned long currentTime = millis();

  // 检查当前时间与上次触发时间的差是否大于防抖动时间
  if (currentTime - lastDebounceTime > DEBOUNCE_TIME) {
    // 更新上次触发时间
    lastDebounceTime = currentTime;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(touch1Semaphore, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken == pdTRUE) {
      portYIELD_FROM_ISR();
    }


    // // 检查触摸传感器状态
    // if (touchRead(TOUCH_SENSOR_PIN) < 40) {
    //   // 如果触摸传感器被触摸，打印消息
    //   if (!isButtonPressed) {
    //     Serial.println("Button pressed!");
    //     isButtonPressed = true;
    //   }
    // } else {
    //   // 如果触摸传感器没有被触摸，打印消息
    //   if (isButtonPressed) {
    //     Serial.println("Button released!");
    //     isButtonPressed = false;
    //   }
    // }
  
  }

}