void Init_html(){
                                       
  server.on("/", [](){server.send(200, "text/html", Main_HTML());});                                                  //Гдавная страница
  server.on("/Lamp1On",  []() {digitalWrite(D1_pin, HIGH) ; server.send(200, "text/html", Main_HTML()); delay(10);}); 
  server.on("/Lamp1Off", []() {digitalWrite(D1_pin, LOW)  ; server.send(200, "text/html", Main_HTML()); delay(10);});
  server.on("/Lamp2On",  []() {digitalWrite(D2_pin, HIGH) ; server.send(200, "text/html", Main_HTML()); delay(10);});  
  server.on("/Lamp2Off", []() {digitalWrite(D2_pin, LOW)  ; server.send(200, "text/html", Main_HTML()); delay(10);}); 
  server.on("/settings", []() {server.send(200, "text/html", Settings_HTML()); delay(10);});                          // страница с настройками wifi/ap
  server.on("/settings_clock", []() {server.send(200, "text/html", SettingsClock_HTML()); delay(10);});               // страница с настройками часов
  server.on("/save",     []() {server.send(200, "text/html", Save_HTML())    ; delay(10);});                          // запись данных в память устройства
  httpUpdater.setup(&server);                                                                                         // обновления через web-интерфейс  http://{local_IP}/update  
  server.begin();
}
