#ifndef MAIN_H
#define MAIN_H
#include "BluetoothSerial.h"
#include "ArduinoJson.h"
#include "WiFi.h"
#include "Arduino.h"
#include "DS3231.h"
#include "Wire.h"
#include "ShiftRegister74HC595.h"
#include "Wire.h"


#define DataPin 14
#define LatchPin 32
#define ClkPin 33
#define I2C_SCL 21
#define I2C_SDA 22


extern String data_app;
extern BluetoothSerial SerialBT;
extern int threshold;

extern TaskHandle_t Task0_Handle;
extern TaskHandle_t Task1_Handle;
extern TaskHandle_t Task2_Handle;
extern TaskHandle_t Task3_Handle;

// 创建触摸按键中断信号量
extern SemaphoreHandle_t touch1Semaphore;
extern SemaphoreHandle_t touch2Semaphore;
extern SemaphoreHandle_t touch3Semaphore;

#endif