
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ESP8266HTTPUpdateServer.h>
#include <Ticker.h>                         
#include "sntp.h"

struct ESP_Config {                         // структура для хранения настроек в EEPROM памяти. Переменные структуры записаны большими буквами, для их отличия от других глобальных переменных
  char    MUSOR[16] = {};                   // в начале сектора EEPROM содержатся какие-то данные ESP, запись туда важных данных нежелательна
  // Наименование в режиме клиента и IP адресс
  char    WIFI_SSID[32] = {};               // имя сети
  char    WIFI_PASSWORD[32] = {};           // пароль сети
  char    IP_ADDRESS[16] = {};              // IP адресс
  char    GETEWAY[16] = {};                 // шлюз
  char    SUBNET[16] = {};                  // маска
  // Параметры подключения в режиме точки доступа
  char    AP_SSID[32] = {};                 // имя точки доступа
  char    AP_PASSWORD[32] = {};             // пароль точки доступа
  // Параметры часов
  bool    SYNC_CLOCK = 0;                   // разрешение на синхронизацию
  int     GMT = 0;                          // часовой пояс   
  uint8_t INTERVAL_SYNC = 0;                // интервал синхронизации часов
  
  char    TOKEN[64] = {};                   // API Token Blynk.io
  
 uint8_t  CONTROL_EEPROM_DEFAULT = 0;       // проверка EEPROM памяти на сохранненые ранее параметры
  
} Config;


ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer server(80);
Ticker timer_clock;                           // объект класса, для вызова счетчика времени. Раскоментировать если нет RTC


int D1_pin = 5;                               //D1 pin GPIO5
int D2_pin = 4;                               //D2 pin GPIO4

uint8_t first_oct;                            // первый октет IP/getaway/subnet
uint8_t second_oct;                           // второй октет IP/getaway/subnet
uint8_t third_oct;                            // третий октет IP/getaway/subnet
uint8_t fourth_oct;                           // четвертый октет IP/getaway/subnet

String ArrDayOfWeek[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" }; // массив дней недели
byte indexDayOfWeek = 0;
String ArrMonth [12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; // массив месяцев
byte indexMonth = 0;
byte hh = 0;                                   // часы
byte mm = 0;                                   // минуты
byte ss = 0;                                   // секунды
uint16_t year = 0;                             // год
byte date = 0;                                 // число месяца
unsigned long interval_sync = 43200000;        // интервал синхронизации часов  
unsigned long sync_previousMillis = 0;

void setup(void){
  Serial.println("\n");
  delay(100);
  Serial.begin(115200);
  EEPROM.begin(sizeof(Config));                       // инициализация EEPROM памяти в размере = размеру структуры Config
  Serial.println("\nИнициализированно " + String(sizeof(Config)) + " byte EEPROM памяти");
     
 

  Read_Config();
  
  if (Config.CONTROL_EEPROM_DEFAULT != 0xAA){         // проверка EEPROM памяти на наличие корректных настроек
      SetDefaultSettings();
      Read_Config();
  }
  else WiFi_init();
  
  Init_html();
  

  timer_clock.attach(1, clock_);                      // прерывание для часов.  Раскоментировать если нет RTC

    
  // preparing GPIOs
  pinMode(D1_pin, OUTPUT);
  digitalWrite(D1_pin, LOW);
  pinMode(D2_pin, OUTPUT);
  digitalWrite(D2_pin, LOW);
 
  delay(100);
  Serial.begin(115200);
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
  
  unsigned long currentMillis = millis();
  
        if ((currentMillis - sync_previousMillis > interval_sync))          //тайминг синхронизации часов с сервером
            {
              sync_previousMillis = currentMillis;
              if (Config.SYNC_CLOCK == true) SyncRealTimeClock();
            }
} 
