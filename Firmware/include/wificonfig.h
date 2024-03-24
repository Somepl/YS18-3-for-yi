// 头文件保护宏
#ifndef WIFICONFIG_H
#define WIFICONFIG_H

#include "main.h"
// 初始化
extern bool init_wifi(void);
// 配网函数
extern void bluetooth(void);

extern bool wifiPW(String sid,String pwd);

extern String ipmac();


#endif