// 头文件保护宏
#ifndef TASK_H
#define TASK_H

#include "main.h"
// 打开 LED 
extern void timeDisplay(void *pvParameters);
extern void Touch1Task(void *pvParameters);
extern void Touch2Task(void *pvParameters);
extern void Touch3Task(void *pvParameters);
extern void setClock();



// extern char* ntpServer;
// extern long  gmtOffset_sec;               //定义时区
// extern int   daylightOffset_sec;          //定义时区
// extern uint8_t num[10]; 
// extern uint8_t N[4];
// extern ShiftRegister74HC595<4> sr; 
// extern DS3231 Clock;
// extern bool Century;
// extern bool h12;
// extern bool PM;
extern int second,minute,hour,date,month,year,temperature,h1,h2,m1,m2,h1_flag,h2_flag,m1_flag,m2_flag; 

#endif

