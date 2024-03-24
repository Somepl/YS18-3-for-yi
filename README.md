# esp32 VDF





## 实现功能：

联网报时，天气、温度获取，随意更改显示内容，mqtt远程控制，手机配网，自定义触摸按键...



### 小程序实现功能：

1.配网

2.mqtt

3.随意更改显示内容



### 板载程序流程：

通电——》WiFi打开，freertos运行任务——》三次尝试联网(动画)——》显示时间

​																						|成功

​																		通过ip获取位置信息

​																		联网校准时间

​																		连接mqtt服务器

touch1触发——》blufi配网模式开启——》配网——》3分钟后关闭blufi配网任务和蓝牙

​																			|成功

​																		立即关闭blufi配网任务，关闭蓝牙降低功耗

touch2触发——》显示天气和温度信息——》任务运行完毕

touch3触发——》进行mqtt通信



### 移动端软件流程：

app开启——》页面1：blufi配网

​										mqtt连接状态

​										按钮1：mqtt通信显示图案

​										按钮2：mqtt通信自定义字符



# HARDWARE


## Component

#### 电源  
栅极&阳极：mt3608升压20v  
灯丝：ams1117 1.5or1.2  

#### 驱动  
sn74hc595驱动，达林顿管uln2803a  
 
#### 其他  
供电为typec5V,usb转串口芯片使用cp2102,
时钟使用ds3231，荧光管为YS18-3 * 4  

## Schematic
![SCH_Schematic1_1_2023-06-15](https://github.com/Somepl/YS18-3-for-yi/assets/56122958/2334f733-9261-45cb-b098-40d2a5ed5828)


## Board
![PCB_PCB1_1_2023-12-28](https://github.com/Somepl/YS18-3-for-yi/assets/56122958/b1e7b340-5560-496d-8cb9-174b90f94e1c)

## Entity
![IMG_20240323_162852](https://github.com/Somepl/YS18-3-for-yi/assets/56122958/55d47e16-f70d-4323-a173-1d48dbec4436)

![DSC_5194-2](https://github.com/Somepl/YS18-3-for-yi/assets/56122958/0b7fa5f1-54be-4b72-b6ce-d54f7cf38dae)
