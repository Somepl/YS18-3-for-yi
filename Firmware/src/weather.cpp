#include "weather.h"

//#include "wificonfig.h"







String API = "SR1N2LB9Xwsvr6YCk";

String url = "";
String city = "";
String url_xinzhi = "";
String Weather = "0";
String ip = "0";





String getWeatherURL(String api,String city)
{
  url_xinzhi =  "http://api.seniverse.com/v3/weather/now.json?key=";
  url_xinzhi += api;
  url_xinzhi += "&location=";
  url_xinzhi += city;
  url_xinzhi += "&language=zh-Hans&unit=c";
  return url_xinzhi;
}

String getLocalURL(String api,String ip)
{
  url_xinzhi =  "http://api.seniverse.com/v3/location/search.json?key=";
  url_xinzhi += api;
  url_xinzhi += "&q=";
  url_xinzhi += ip;
  return url_xinzhi;
}


void ParseWeather()
{  
  //WiFiClientSecure *client = new WiFiClientSecure;
  //client -> setInsecure();
  //if(client) 
  //{
  //client -> setCACert(rootCACertificate1);
  HTTPClient https;
  DynamicJsonDocument doc(1024); //分配内存,动态
  https.begin("http://ip.useragentinfo.com/json?");
  // int httpGet1=https.GET();

  // if(httpGet1 > 0)
  // {
  //   //Serial.println("IP查询 is %d",a1);
  //   if(httpGet1 == HTTP_CODE_OK)
  //   {
  //     String json1 = https.getString();
  //     //Serial.println(json1);
  //     deserializeJson(doc, json1);
  //     ip=doc["data"]["ip"].as<String>();
  //     //Serial.println(local);
  //   }
  //   else
  //   {
  //     Serial.println(httpGet1);
  //     Serial.printf("IP ERROR1!服务器回复不是200");
  //   }
  // }
  // else
  // {
  //   Serial.printf("IP ERROR2!!GET请求失败");
  // }



  //client -> setCACert(rootCACertificate1);

  //doc.clear();

  //url=getLocalURL(API,ip);
  //https.begin(*client,  url);
  int httpGet2 = https.GET();

  if(httpGet2 > 0)
  {
    //Serial.println("IP查询 is %d",a1);
    if(httpGet2 == HTTP_CODE_OK)
    {
        String json2 = https.getString();
        //Serial.println(json2);
        deserializeJson(doc, json2);
    //local=doc["results"][0]["now"]["text"].as<String>();
        city = doc["city"].as<String>();  
        //Serial.println(city);
    }
    else
    {
      Serial.println(httpGet2);
      Serial.printf("城市ERROR1!!服务器回复不是200");
    }
  }
  else
  {
    Serial.printf("城市ERROR2!!GET请求失败");
  }





  doc.clear();
  url=getWeatherURL(API,city);
  
  https.begin( url);
  int httpGet3 = https.GET();
  if(httpGet3 > 0)
  {
    //Serial.printf("HTTPGET is %d",httpGet);
    if(httpGet3 == HTTP_CODE_OK)
    {
      String json3 = https.getString();
      //Serial.println(json);
      deserializeJson(doc, json3);
      //local=doc["results"][0]["now"]["text"].as<String>();
      Weather = doc["results"][0]["now"]["text"].as<String>();  
    }
    else
    {
      Serial.println(httpGet3);
      Serial.printf("天气ERROR1!!服务器回复不是200");
    }
  }
  else
  {
    Serial.printf("天气ERROR2!!GET请求失败");
  }
  https.end();
  

  //delete client;
//} else {
 // Serial.println("Unable to create client");
//}
}



