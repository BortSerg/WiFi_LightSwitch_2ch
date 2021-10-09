String Save_HTML (void){
String out = "";
  
out += "<!DOCTYPE html>";
out += "<html lang=\"ru\">";
out += "<head>";
out +=     "<meta name=\"viewport\" charset=\"utf-8\" content=\"user-scalable=0, width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0\">";
out +=     "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=Edge\">";
out +=     "<title>Сохранение | ESP8266 Light Server</title>";
out += "</head>";

out += "<body>";
out += "<script LANGUAGE='JavaScript'>";
  
  if (server.hasArg("wifi_ssid") & server.hasArg("wifi_password") & server.hasArg("ip_address") & server.hasArg("geteway") & server.hasArg("subnet") &  server.hasArg("ap_ssid") & server.hasArg("ap_password"))
  {
    strcpy(Config.WIFI_SSID, server.arg("wifi_ssid").c_str());
    strcpy(Config.WIFI_PASSWORD, server.arg("wifi_password").c_str());
    strcpy(Config.IP_ADDRESS, server.arg("ip_address").c_str());
    strcpy(Config.GETEWAY, server.arg("geteway").c_str());
    strcpy(Config.SUBNET, server.arg("subnet").c_str());
    strcpy(Config.AP_SSID, server.arg("ap_ssid").c_str());
    strcpy(Config.AP_PASSWORD, server.arg("ap_password").c_str());
    delay(100);
    save_Config();
    Serial.println("Настройки сети сохранены в EEPROM память.\n");
    out +=   "window.alert('Параметры сохранены. Чтобы новые параметры вступили в действие перезагрузите устройство');";
    out +=   "window.location.href='/';";
  }


  
  if ((server.arg("sync_clock") == "1" && server.hasArg("timezone")) || (server.arg("sync_clock") == "1" && server.hasArg("timezone") && server.hasArg("hh") && server.hasArg("mm") && server.hasArg("ss")) )                                                 
  {                                                                                                                 // включение синхронизации
    if (Config.SYNC_CLOCK != server.arg("sync_clock").toInt() ||  Config.GMT != server.arg("timezone").toInt())     // защита записи в EEPROM если параметры не изменились
          {
              Config.SYNC_CLOCK = server.arg("sync_clock").toInt();
              Config.GMT = server.arg("timezone").toInt();
              save_Config();
              Serial.println("Настройки часов сохранены в EEPROM память."); 
          }
          
    if (WiFi.status() == WL_CONNECTED)
      {
              SyncRealTimeClock(); 
              out +=   "window.alert('Произведена АВТОМАТИЧЕСКАЯ корректировка ДАТЫ и ВРЕМЕНИ.');";
              Serial.println("Дата и время синхронизированы.\n");
      }
      
    if (WiFi.status() != WL_CONNECTED)
      {
          out +=   "window.alert('Отстствует подключение к сети. Коректировка времени произойдет при подключении к интернету атоматически, после ПЕРЕЗАГРУЗКИ устройства');";
          Serial.println("Нет подключение к Wi-Fi. Синхронизация отложена до перезагрузки.\n");
      }
    out +=   "window.location.href='/settings_clock';";  
  }


  if (server.arg("sync_clock") == "0" && server.hasArg("timezone"))                                                  // отключение синхронизации 
  {
      if (Config.SYNC_CLOCK != server.arg("sync_clock").toInt() ||  Config.GMT != server.arg("timezone").toInt())    // защита записи в EEPROM если параметры не изменились
          {
              Config.SYNC_CLOCK = server.arg("sync_clock").toInt();
              Config.GMT = server.arg("timezone").toInt();
              save_Config();
              Serial.println("Настройки часов сохранены в EEPROM память."); 
          }
      Serial.println("Синхронизация даты и времени отключена.\n"); 
      out +=   "window.location.href='/settings_clock';";  
  }

  if (server.arg("sync_clock") == "0" && server.hasArg("hh") && server.hasArg("mm") && server.hasArg("ss") && server.hasArg("dayOfWeek") && server.hasArg("date") && server.hasArg("month") && server.hasArg("year"))          
  {                                                                                                                   // установка врмени вручную
     hh             = server.arg("hh").toInt();
     mm             = server.arg("mm").toInt();
     ss             = server.arg("ss").toInt();
     indexDayOfWeek = server.arg("dayOfWeek").toInt();
     date           = server.arg("date").toInt();
     indexMonth     = server.arg("month").toInt();
     year           = server.arg("year").toInt();

     Serial.println("Дата и время установлены вручную.\n");
     out +=   "window.alert('Параметры сохранены. Время и дата изменены.');";
     out +=   "window.location.href='/settings_clock';";
  }

out +=   "</script>\");";
out += "</body>";
out += "</html>";
return (out);
delay(10);
}



void save_Config() {
 size_t sz1 = sizeof(Config);
 for (unsigned int i = 0; i < sz1; i++)
 EEPROM.write(i, *((uint8_t*)&Config + i));
 EEPROM.commit();
}
