String Main_HTML (void){
  
  String out = "";
  
out += "<!DOCTYPE html>";
out += "<html>";
out += "<head lang=\"ru\">";
out +=    "<meta name=\"viewport\" charset=\"utf-8\" content=\"user-scalable=0, width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0\">";
out +=    "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=Edge\">";
out +=    "<title>Главная | ESP8266 Light Server</title>";
out +=    "<style type=\"text/css\">";
out += Create_CSS();
out +=    "</style>";
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


out +=        "<div><p class=\"mode\">---- LAMP 1 ----</p>";
if (digitalRead(D1_pin) == HIGH){
out +=        "<div class=\"mode_ON\">ON</div> <!-- квадрас с подсветочкой Lamp1 -->";
}
if (digitalRead(D1_pin) == LOW){
out +=        "<div class=\"mode_OFF\">OFF</div>";
}
out +=        "<div class=\"button_mode\"> <a href=\"/Lamp1On\"><button>ON</button></a>&nbsp;<a href=\"/Lamp1Off\"><button>OFF</button></a></div>";

  
out +=        "<div><p class=\"mode\">---- LAMP 2 ----</p></div>";
if (digitalRead(D2_pin) == HIGH){  
out +=        "<div class=\"mode_ON\">ON</div> <!-- квадрас с подсветочкой Lamp2 -->";
}
if (digitalRead(D2_pin) == LOW){
out +=        "<div class=\"mode_OFF\">OFF</div>";
} 
out +=        "<div class=\"button_mode\"> <a href=\"/Lamp2On\"><button>ON</button></a>&nbsp;<a href=\"/Lamp2Off\"><button>OFF</button></a></div>";
     
out +=        "<div class=\"button_refresh\"><a href=\"/\"><button style=\"width:158px;\">REFRESH</button></a></div></div>";

out +=    "</body>";
out +="</html>";
    
return (out);  
delay(10);
}
