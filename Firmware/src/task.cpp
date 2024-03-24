#include "task.h"
#include "wificonfig.h"



const char* ntpServer = "asia.pool.ntp.org";
const long  gmtOffset_sec = 4*3600;               //定义时区
const int   daylightOffset_sec = 4*3600;          //定义时区
//struct tm timeinfo;
int second,minute,hour,date,month,year,temperature,h1,h2,m1,m2,h1_flag,h2_flag,m1_flag,m2_flag; 

uint8_t num[10]={B00000011 , B10011111 , B00100101 , B00001101 , B10011001 , B01001001 , B01000001 , B00011111 , B00000001 , B00001001 }; 
uint8_t N[4];



ShiftRegister74HC595<4> sr(DataPin, ClkPin, LatchPin); 
DS3231 Clock;
bool Century=false;
bool h12;
bool PM;


void setClock()
{
  struct tm timeinfo; //声明一个结构体
  configTime(8 * 3600, 0, ntpServer);
  if (!getLocalTime(&timeinfo))
  { //一定要加这个条件判断，否则内存溢出
    Serial.println("Failed to obtain time");
    return;
  }

  // Serial.println(&timeinfo, "%A, %Y-%m-%d %H:%M:%S");
  // Clock.setSecond(timeinfo.tm_sec);          //Set the second 
  // Clock.setMinute(timeinfo.tm_min);          //Set the minute 
  // Clock.setHour(timeinfo.tm_hour);           //Set the hour
  // Clock.setDoW(timeinfo.tm_wday + 1);        //Set the day of the week
  // Clock.setDate(timeinfo.tm_mday);           //Set the date of the month
  // Clock.setMonth(timeinfo.tm_mon + 1);       //Set the month of the year
  // Clock.setYear(timeinfo.tm_year%100);       //Set the year (Last two digits of the year)

  second=timeinfo.tm_sec;
  minute=timeinfo.tm_min;
  hour=timeinfo.tm_hour;
  date=timeinfo.tm_mday;
  year=timeinfo.tm_year%100;
  month=timeinfo.tm_mon + 1;
}



// void showTime()
// {
//   second=Clock.getSecond();
//   minute=Clock.getMinute();
//   hour=Clock.getHour(h12, PM);
//   date=Clock.getDate();
//   year=Clock.getYear();
//   month=Clock.getMonth(Century);
//   temperature=Clock.getTemperature();


//   h1=hour/10;   
//   h2=hour%10;
//   m1=minute/10;
//   m2=minute%10;
//   if(h1!=h1_flag)
//   {
//     for(int i=0;i<10;i++)
//     {
//       N[0]=num[i];
//       sr.setAll(N);
//       delay(50);
//     }
//     N[0]=num[h1];
//     sr.setAll(N);
//     sr.setAllHigh();
//   }
//   if(h2!=h2_flag)
//   {
//     for(int i=0;i<10;i++)
//     {
//       N[1]=num[i];
//       sr.setAll(N);
//       delay(50);
//     }
//     N[0]=num[h1];
//     N[1]=num[h2];
//     sr.setAll(N);
//     sr.setAllHigh();
//   }
//   if(m1!=m1_flag)
//   {
//     for(int i=0;i<10;i++)
//     {
//       N[2]=num[i];
//       sr.setAll(N);
//       delay(50);
//     }
//     N[0]=num[h1];
//     N[1]=num[h2];
//     N[2]=num[m1];
//     sr.setAll(N);
//     sr.setAllHigh();
//   }
//   if(m2!=m2_flag)
//   {
//     for(int i=0;i<10;i++)
//     {
//       N[3]=num[i];
//       sr.setAll(N);
//       delay(50);
//     }
//     N[0]=num[h1];
//     N[1]=num[h2];
//     N[2]=num[m1];
//     N[3]=num[m2];
//     sr.setAll(N);
//     sr.setAllHigh();
//   }

  
//   N[0]=num[h1];
//   N[1]=num[h2];
//   N[2]=num[m1];
//   N[3]=num[m2];
//   sr.setAll(N);
//   delay(900);
//   h1_flag=h1;
//   h2_flag=h2;
//   m1_flag=m1;
//   m2_flag=m2;
// }



void timeDisplay(void *pvParameters){
  for (;;){ 
  //showTime();

  Serial.print("20");
  Serial.print(year,DEC);
  Serial.print('-');
  Serial.print(month,DEC);
  Serial.print('-');
  Serial.print(date,DEC);
  Serial.print(' ');
  Serial.print(hour,DEC);
  Serial.print(':');
  Serial.print(minute,DEC);
  Serial.print(':');
  Serial.print(second,DEC);
  Serial.print('\n');
  // Serial.print("Temperature=");
  // Serial.print(temperature); 
  // Serial.print('\n');

  vTaskDelay(1000 / portTICK_PERIOD_MS);

  // if(hour==6)
  // {
  //   if(WiFi.status()==WL_CONNECTED)
  //     setClock();
  // }
  }
}


void Touch1Task(void *pvParameters){  // This is a task.
    //pinMode(2, OUTPUT);
    for (;;){ // A Task shall never return or exit.
    xSemaphoreTake(touch1Semaphore, portMAX_DELAY);
    // 挂起任务一
    vTaskSuspend(Task0_Handle);
    // 执行任务二的操作
    unsigned long startTime = millis();
    unsigned long currentTime = millis();
    Serial.println("开始配网");
    while (currentTime - startTime < 60000)
    {
      bluetooth();
      currentTime = millis();
    }
    Serial.println("配网结束");
    // 在这里执行任务二的操作，例如某些处理或等待超时等
    // 恢复任务一
    vTaskResume(Task0_Handle);
    
  }
}




void Touch2Task(void *pvParameters){  // This is a task.
    //pinMode(2, OUTPUT);
    for (;;){ // A Task shall never return or exit.

    Serial.println("时间");
    //Serial.println(threshold++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}