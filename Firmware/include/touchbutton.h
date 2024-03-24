// 头文件保护宏
#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H

#include "main.h"
// 打开 LED

void gotTouch1(); 
void gotTouch2();
void gotTouch3();


#define TOUCH_SENSOR_PIN T0
#define DEBOUNCE_TIME 500 // 触摸按键的防抖动时间，单位：毫秒

//bool isButtonPressed = false;
static unsigned long lastDebounceTime = 0; // 上一次触发的时间

#endif