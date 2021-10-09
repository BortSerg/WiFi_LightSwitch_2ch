void SetDefaultSettings(){

    String ssid = "Your SSID Wi-Fi";                          // вписать SSID вашей сети
    String pass = "Your Pass Wi-Fi ";                         // и пароль от сети 
    String ipaddress = "192.168.3.100";                       // статический адрес устройства в вашей сети
    String geteway = "192.168.3.1";                           // шлюз (удрес роутера)
    String subnet = "255.255.255.0";                          // маска подсети
    String ap_ssid = "Light Server";                          // имя устройства в режими точки доступа (по умолчанию адрес точки доступа на базе ESP8266 192.168.4.1)
    String ap_pass = "";                                      // пароль от точки доступа
    
    strcpy(Config.WIFI_SSID, ssid.c_str());
    strcpy(Config.WIFI_PASSWORD, pass.c_str());
    strcpy(Config.IP_ADDRESS, ipaddress.c_str());
    strcpy(Config.GETEWAY, geteway.c_str());
    strcpy(Config.SUBNET, subnet.c_str());
    strcpy(Config.AP_SSID, ap_ssid.c_str());
    strcpy(Config.AP_PASSWORD, ap_pass.c_str());
    
    Config.CONTROL_EEPROM_DEFAULT = 0xAA;
    
    Config.SYNC_CLOCK = 1;
    Config.GMT = 3;
    Config.INTERVAL_SYNC = 12;
    save_Config();
 
}
