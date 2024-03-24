// #include <WiFi.h>
// #include "time.h"
// #include <DS3231.h>
// #include <Wire.h>
// #include <ShiftRegister74HC595.h>
// #define DataPin 14
// #define LatchPin 32
// #define ClkPin 33


// const char* ssid       = "一";         //连接的WIFI名字
// const char* password   = "mmbnxy8gzf";    //连接的WIFI密码
 
// const char* ntpServer = "asia.pool.ntp.org";
// const long  gmtOffset_sec = 4*3600;               //定义时区
// const int   daylightOffset_sec = 4*3600;          //定义时区
// struct tm timeinfo;
// int hour,minute,h1,h2,m1,m2;

// uint8_t num[10]={B00000011 , B10011111 , B00100101 , B00001101 , B10011001 , B01001001 , B01000001 , B00011111 , B00000001 , B00001001 }; 
// uint8_t N[4];
// uint8_t smile[4]={B11000101 , B00111011 , B00111011 , B11000101 };
// uint8_t sad[4]={B11010111 , B00111001 , B00111001 , B11010111 };
// uint8_t nol[4]={B11111111 , B01000100 , B01000100 , B11111111 };
// uint8_t love[5]={B11100011 , B00000011 , B11000111 , B01100001 , B11111111 };

// ShiftRegister74HC595<4> sr(DataPin, ClkPin, LatchPin); 

// /*
// void Smile()
// {
//  sr.setAll(smile);
//  delay(1000);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(smile);
//  delay(300);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(smile);
//  delay(1000);

// }

// void Sad()
// {
//  sr.setAll(sad);
//  delay(1000);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(sad);
//  delay(300);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(sad);
//  delay(1000);
// }

// void Nol()
// {
//  sr.setAll(nol);
//  delay(1000);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(nol);
//  delay(300);
//  sr.setAllHigh();
//  delay(300);
//  sr.setAll(nol);
//  delay(1000);
// }

// void TimeDisplay(){
//   hour=timeinfo.tm_hour%12;
//   minute=timeinfo.tm_min;
//   if(hour==0)
//   hour=12;
//   h1=hour/10;   
//   h2=hour%10;
  
//   m1=timeinfo.tm_min/10;
//   m2=timeinfo.tm_min%10;
//   N[0]=num[h1];
//   N[1]=num[h2];
//   N[2]=num[m1];
//   N[3]=num[m2];
//   sr.setAll(N);
// }

// */


// void Sunshine(int n)
// {
//   uint8_t sun1[4]={B01101101 , B01100011 , B00001111 , B01101101 };
//   uint8_t sun2[4]={B11111111 , B01100011 , B00001111 , B11111111 };
//   for(int i=0;i<n;i++)
//   {
//     sr.setAllHigh();
//     sr.setAll(sun1);
//     delay(400);
//     sr.setAllHigh();
//     sr.setAll(sun2);
//     delay(400);
//   }

//   sr.setAllHigh();
// }

// void Raining(int n)
// {
//   uint8_t rain1[4]={B10111111 , B10111111 , B10111111 , B10111111 };
//   uint8_t rain2[4]={B11011111 , B11011111 , B11011111 , B11011111 };
//   uint8_t rain3[4]={B11111011 , B11111011 , B11111011 , B11111011 };
//   for(int i=0;i<n;i++)
//   {
//     sr.setAllHigh();
//     sr.setAll(rain1);
//     delay(150);
//     sr.setAllHigh();
//     sr.setAll(rain2);
//     delay(150);
//     sr.setAllHigh();
//     delay(200);
//   }
//   for(int i=0;i<n;i++)
//   {
//     sr.setAllHigh();
//     sr.setAll(rain3);
//     delay(150);
//     sr.setAllHigh();
//     sr.setAll(rain2);
//     delay(150);
//     sr.setAllHigh();
//     delay(200);
//   }
// }

// void Cloudy(int n)
// {

// }

// void Love(int n)
// {
//   uint8_t l1[4]={love[0] , love[1] , love[2] , love[3] };
//   uint8_t l2[4]={love[4] , love[0] , love[1] , love[2] };
//   uint8_t l3[4]={love[4] , love[4] , love[0] , love[1] };
//   uint8_t l4[4]={love[3] , love[4] , love[4] , love[0] };
//   uint8_t l5[4]={love[2] , love[3] , love[4] , love[4] };
//   uint8_t l6[4]={love[1] , love[2] , love[3] , love[4] };
//   for(int i=0;i<n;i++)
//   {
//     sr.setAllHigh();
//     sr.setAll(l1);
//     delay(700);
//     sr.setAllHigh();
//     sr.setAll(l2);
//     delay(700);
//     sr.setAllHigh();
//     sr.setAll(l3);
//     delay(700);
//     sr.setAllHigh();
//     sr.setAll(l4);
//     delay(700);
//     sr.setAllHigh();
//     sr.setAll(l5);
//     delay(700);
//     sr.setAllHigh();
//     sr.setAll(l6);
//     delay(700);
//   }

//   sr.setAllHigh();

// }

// // void setup()
// // {
// //   Serial.begin(115200);


// // }

// // void loop()
// // {
// //   //Sunshine(6);
// //   //delay(3000);
// //   //Raining(6);
// //   //delay(3000);
// //   //Cloudy(3);
// //   //delay(3000);
// //   Love(6);
// //   delay(3000);

// // }
