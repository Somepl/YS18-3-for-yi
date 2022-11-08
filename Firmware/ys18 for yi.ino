#include <WiFi.h>
#include "time.h"
#include <ShiftRegister74HC595.h>
#define DataPin 14
#define LatchPin 32
#define ClkPin 33


const char* ssid       = "一";         //连接的WIFI名字
const char* password   = "mmbnxy8gzf";    //连接的WIFI密码
 
const char* ntpServer = "asia.pool.ntp.org";
const long  gmtOffset_sec = 4*3600;               //定义时区
const int   daylightOffset_sec = 4*3600;          //定义时区
struct tm timeinfo;
int hour,minute,h1,h2,m1,m2;

uint8_t num[10]={B00000011 , B10011111 , B00100101 , B00001101 , B10011001 , B01001001 , B01000001 , B00011111 , B00000001 , B00001001 }; 
uint8_t N[4];



ShiftRegister74HC595<4> sr(DataPin, ClkPin, LatchPin); 


void printLocalTime()
{
  
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %Y-%m-%d %H:%M:%S");
}



void wificonnection(){    //连接wifi
    
    if(WiFi.status() != WL_CONNECTED){
      Serial.printf("Connecting to %s ", ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
       }
    Serial.println("CONNECTED");
    }
   configTime(8 * 3600, 0, ntpServer);

  while(!getLocalTime(&timeinfo)){
    configTime(8 * 3600, 0, ntpServer);
    Serial.println("Failed to obtain time");
    
  }
    
  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
    Serial.println("WiFi disconnected!");
}


void TimeDisplay(){
  hour=timeinfo.tm_hour%12;
  minute=timeinfo.tm_min;
  if(hour==0)
  hour=12;
  h1=hour/10;   
  h2=hour%10;
  
  m1=timeinfo.tm_min/10;
  m2=timeinfo.tm_min%10;
  N[0]=num[h1];
  N[1]=num[h2];
  N[2]=num[m1];
  N[3]=num[m2];
  sr.setAll(N);
}



 
void setup()
{
  Serial.begin(115200);
  for(int i=0;i<3;i++);
  {
  delay(1000);
  sr.setAllLow();
  delay(1000);
  sr.setAllHigh();
  }
  wificonnection();
}
 
void loop()
{
  
  printLocalTime();
  TimeDisplay();
}
