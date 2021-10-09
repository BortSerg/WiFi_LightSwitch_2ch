void WiFi_init(){
 Convert(Config.IP_ADDRESS);
 delay(100);
 IPAddress ip(first_oct, second_oct, third_oct, fourth_oct);       //Статический  IP
 Serial.println("STATIC IP " +String(first_oct)+ "." +String(second_oct)+ "." +String(third_oct)+"." +String(fourth_oct));
 
 Convert(Config.GETEWAY);
 delay(100);
 IPAddress gateway(first_oct, second_oct, third_oct, fourth_oct);  //Шлюз (Gateway)
 Serial.println("GETEWAY " +String(first_oct)+ "." +String(second_oct)+ "." +String(third_oct)+"." +String(fourth_oct));
 
 Convert(Config.SUBNET);
 delay(100);
 IPAddress subnet(first_oct, second_oct, third_oct, fourth_oct);   //Маска
 Serial.println("SUBNET " +String(first_oct)+ "." +String(second_oct)+ "." +String(third_oct)+"." +String(fourth_oct));

 //WiFi.config(ip, gateway, subnet);
 WiFi.mode(WIFI_STA);                                             //режим подключения к роутреру
 byte tries = 11;                                                 //количество попыток

 IPAddress dns(8, 8, 8, 8);                                       //Google dns
 
 WiFi.begin(String(Config.WIFI_SSID), String(Config.WIFI_PASSWORD));
 WiFi.config(ip, dns, gateway, subnet); 
 
 while (--tries && WiFi.status() != WL_CONNECTED) 
     //  Serial.println("Connecting to the router");
      {
        delay(1000);
        Serial.print(".");
      }
 if (WiFi.status() != WL_CONNECTED)                               //если нет подключения к роутеру
      {
        Serial.println("");
        Serial.print("ESP starting AP-mode");
        WiFi.disconnect();
        delay(10);
        WiFi.mode(WIFI_AP);                                       //поднять точку тоступа
        WiFi.softAP(String(Config.AP_SSID), String(Config.AP_PASSWORD));   //имя, пароль, --> канал, видимость, количество одновременных подключений (1..8) <--
        Serial.println("");
        Serial.println("Run AP-mode");
        Serial.print("AP SSID: ");
        Serial.println(String(Config.AP_SSID));
        Serial.print("AP IP address: ");
        Serial.println(WiFi.softAPIP());
        Serial.println("WiFi MAC: " + String(WiFi.softAPmacAddress()));

      }
  else
      {
        Serial.println("");
        Serial.print("Connected to ");
        Serial.println(String(Config.WIFI_SSID));
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("WiFi MAC: " + String(WiFi.macAddress()));
        if (Config.SYNC_CLOCK == 1) SyncRealTimeClock();
      }
 }
