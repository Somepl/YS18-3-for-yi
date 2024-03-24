// 头文件保护宏
#ifndef TASK_H
#define TASK_H

#include "main.h"
// 打开 LED 
void timeDisplay(void *pvParameters);
void Touch1Task(void *pvParameters);
void Touch2Task(void *pvParameters);
void Touch3Task(void *pvParameters);


void setClock();


extern int second,minute,hour,date,month,year,temperature,h1,h2,m1,m2,h1_flag,h2_flag,m1_flag,m2_flag; 

#endif

