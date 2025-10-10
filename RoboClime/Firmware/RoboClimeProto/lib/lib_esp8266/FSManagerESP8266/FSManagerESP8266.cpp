#include "FSManagerESP8266.h"
#include <LittleFS.h>

bool FSManagerESP8266::Setup()
{
   return LittleFS.begin();
   
}

bool FSManagerESP8266::Exists(const String& shortFileName)
{
    return LittleFS.exists("/"+shortFileName);
}

String FSManagerESP8266::ReadFile(const String& shortFileName)
{

  File file = LittleFS.open("/"+shortFileName, "r");
  
  if (!file) {
    return "";
  }

  String content = "";

  int cnt=0;
  while(file.available())
  {
    cnt++;
    content = content + char(file.read());
  }
  file.close(); 

  return content;
}