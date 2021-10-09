String Settings_HTML (void) {
 
  String out = "";

out += "<!DOCTYPE html>";
out += "<html>";
out += "<head lang=\"ru\">";
out +=    "<meta name=\"viewport\" charset=\"utf-8\" content=\"user-scalable=0, width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0\">";
out +=    "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=Edge\">";
out +=    "<title>Настройки | ESP8266 Light Server</title>";
out +=    "<style type=\"text/css\">";
out += Create_CSS();
out +=    "</style>";

out +=    "<script type=\"text/javascript\"> function check() {";
out +=    "var inp1 = document.getElementById('wifi_ssid');";
out +=        "inp2 = document.getElementById('wifi_password');";
out +=        "inp3 = document.getElementById('ip_address');";
out +=        "inp4 = document.getElementById('geteway');";
out +=        "inp5 = document.getElementById('subnet');";
out +=        "inp6 = document.getElementById('ap_ssid');";
out +=        "inp7 = document.getElementById('ap_password');";
out +=    "document.getElementById('save').disabled = inp1.value || inp2.value || inp3.value || inp4.value || inp5.value || inp6.value || inp7.value ? false : \"disabled\";}";
out +=    "</script>";
out +="</head>";

out +=    "<body>";

out +=        "<header>";
out +=            "<p><img src=\"https://i.ibb.co/Ldh1Tyx/logo.png\" class=\"img-center\"></p>";
out +=             "<p align=\"center\"><font class=\"heder-size\">ESP8266 Light Server</font></p>";
out +=             "<p align=\"center\"><font class=\"slogan\">Управляй светом легко!</font></p>";
out +=        "</header>";
        
out +=        "<header class=\"navig\">";
out +=             "<p><a href=\"/\">Главная</a> <a href=\"/settings\">Настройки</a> <a href=\"/settings_clock\">Часы</a>";
out +=        "</header>";

out +="<div style=\"display: flex; justify-content: center;\">";  
out +=      "<div class=\"main\">";
out +=        "<form action=\"/save\" method=\"get\">";
out +=          "<div class=\"field\">";
out +=          "<label for=\"wifi_ssid\">SSID</label>";
out +=          "<input type=\"text\" name=\"wifi_ssid\" id=\"wifi_ssid\" autocomplete=\"off\" value=\"" + String(Config.WIFI_SSID) + "\" onkeyup=\"check();\">";
out +=          "</div>";
out +=          "<div  class=\"field\">";
out +=          "<label for=\"wifi_password\">Password</label>";
out +=          "<input type=\"password\" name=\"wifi_password\" id=\"wifi_password\" autocomplete=\"off\" value=\"" + String(Config.WIFI_PASSWORD) + "\" onkeyup=\"check();\">";
out +=          "</div>";
out +=          "<div class=\"field\">";
out +=          "<label for=\"ip_address\">IP Address</label>";
out +=          "<input type=\"text\" name=\"ip_address\" id=\"ip_address\"  placeholder=\"xxx.xxx.xxx.xxx\" pattern=\"\\d{1.3}\\.\\d{1.3}.\\d{1.3}.\\d{1.3}\" autocomplete=\"off\" value=\"" + String(Config.IP_ADDRESS) + "\" onkeyup=\"check();\" >";
out +=          "</div>";
out +=          "<div  class=\"field\">";
out +=          "<label for=\"geteway\">Geteway</label>";
out +=          "<input type=\"text\" name=\"geteway\" id=\"geteway\"  placeholder=\"xxx.xxx.xxx.xxx\" pattern=\"\\d{1.3}\\.\\d{1.3}.\\d{1.3}.\\d{1.3}\" autocomplete=\"off\" value=\"" + String(Config.GETEWAY) + "\" onkeyup=\"check();\" >";
out +=          "</div>";
out +=          "<div  class=\"field\">";
out +=          "<label for=\"subnet\">Subnet</label>";
out +=          "<input type=\"text\" name=\"subnet\" id=\"subnet\" placeholder=\"xxx.xxx.xxx.xxx\" pattern=\"\\d{1.3}\\.\\d{1.3}.\\d{1.3}.\\d{1.3}\" autocomplete=\"off\" value=\"" + String(Config.SUBNET) + "\" onkeyup=\"check();\" >";
out +=          "</div>";
out +=          "<p></p><p></p>";
out +=          "<div  class=\"field\">";
out +=          "<label for=\"ap_ssid\">AP SSID</label>";
out +=          "<input type=\"text\" name=\"ap_ssid\" id=\"ap_ssid\" required=\"required\" autocomplete=\"off\" value=\"" + String(Config.AP_SSID) + "\" onkeyup=\"check();\">";
out +=          "</div>";
out +=          "<div  class=\"field\">";
out +=          "<label for=\"ap_password\">AP Password</label>";
out +=          "<input type=\"password\" name=\"ap_password\" id=\"ap_password\" autocomplete=\"off\" value=\"" + String(Config.AP_PASSWORD) + "\" onkeyup=\"check();\">";
out +=          "</div>";      
out +=          "<div class=\"button_submit\">";  
out +=          "<button style=\"height: 40px; width: 100px;\" id=\"save\" disabled=\"disabled\">Сохранить</button>";
out +=          "</div>";
out +=        "</form>";
out +=      "</div>";
out +=    "</div>";
out +=  "</body>";
out +="</html>";
return (out);
delay(10);
}
