// 头文件保护宏
#ifndef WEATHER_H
#define WEATHER_H

#include "main.h"




extern String API;

extern String url;
extern String city;
extern String url_xinzhi;
extern String Weather;
extern String ip;
//extern HTTPClient http;

extern String getWeatherURL(String api,String city);
extern String getLocalURL(String api,String ip);
extern void ParseWeather();
#endif