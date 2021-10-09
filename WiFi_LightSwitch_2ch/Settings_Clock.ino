String SettingsClock_HTML (void){
  String out = "";

out += "<!DOCTYPE html>";
out += "<html>";
out += "<head lang=\"ru\">";
out +=    "<meta name=\"viewport\" charset=\"utf-8\" content=\"user-scalable=0, width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0\">";
out +=    "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=Edge\">";
out +=    "<title>Настройки часов | ESP8266 Light Server</title>";
out +=    "<style type=\"text/css\">";
out +=      Create_CSS();
out +=    "</style>";
  
out +=        "<script type=\"text/javascript\"> function digitalWatch() {var hours   = parseInt('" + String(hh) +"',10);";
out +=                                                                   "var minutes = parseInt('" + String(mm) +"',10);";
out +=                                                                   "var seconds = parseInt('" + String(ss) +"',10);";
out +=                                                                   "var watch   = setInterval(function(){seconds = parseInt(seconds, 10); minutes = parseInt(minutes, 10); hours = parseInt(hours, 10);";
out +=                                                                                           "seconds++;";
out +=                                                                                           "if (seconds>59) { seconds = 0; minutes++;";
out +=                                                                                                              "if (minutes > 59) { minutes = 0; hours++;";
out +=                                                                                                                                  "if(hours > 23) hours = 0;";
out +=                                                                                                                                 "};";
out +=                                                                                                           "}";
                                                                                                                
out +=                                                                    "if (seconds < 10) {seconds = \"0\" + seconds;} ";
out +=                                                                    "if (minutes < 10) {minutes = \"0\" + minutes;} ";
out +=                                                                    "if (hours < 10)   {hours = \"0\" + hours;} ";

out +=                                                                   "document.getElementById(\"digitalWatch\").innerHTML = hours + \":\" + minutes + \":\" + seconds;}, 1000);";
out +=                                                                   "}";

out +=                                                 "function check() { ";
                                                                         if (Config.SYNC_CLOCK == true)
                                                                            {
out +=                                                                          "var inp1 = document.getElementById('syncNTP');";
out +=                                                                          "inp2 = document.getElementById('GMT');";
out +=                                                                          "document.getElementById('save').disabled = inp1.value || inp2.value ? false : \"disabled\";}";
                                                                            }
                                                                         if (Config.SYNC_CLOCK == false)
                                                                            {
out +=                                                                          "var inp1 = document.getElementById('syncNTP');";
out +=                                                                          "inp2 = document.getElementById('GMT');";
out +=                                                                          "inp3 = document.getElementById('hours');";
out +=                                                                          "inp4 = document.getElementById('minutes');";
out +=                                                                          "inp5 = document.getElementById('seconds');";
out +=                                                                          "inp6 = document.getElementById('dayOfWeek');";
out +=                                                                          "inp7 = document.getElementById('date');";
out +=                                                                          "inp8 = document.getElementById('month');";
out +=                                                                          "inp9 = document.getElementById('year');";
out +=                                                                          "document.getElementById('save').disabled = inp1.value || inp2.value || inp3.value || inp4.value || inp5.value || inp6.value || inp7.value || inp8.value || inp9.value ? false : \"disabled\";}";
                                                                            }
                                                                             
out +=       "</script>";
out += "</head>";


  
out += "<body onload=\"digitalWatch()\">";
out += "<header>";
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
if (Config.SYNC_CLOCK == true)
    {
        out +=   "<p>Cинхронизировать время с NTP сервером? <input id=\"syncNTP\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"1\" checked>Да";
        out +=                                             "<input id=\"syncNTP\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"0\">Нет";
        out +=              "<p>Часовой пояс GMT <select id=\"GMT\" onchange=\"check();\" name=\"timezone\" value=\"" + String(Config.GMT) + "\" >";
        out +=                                    "<option value ='-12'>-12</option><option value ='-11'>-11</option><option value ='-10'>-10</option><option value ='-9'>-9</option><option value ='-8'>-8</option><option value ='-7'>-7</option>";
        out +=                                    "<option value ='-6'>-6</option><option value ='-5'>-5</option><option value ='-4'>-4</option><option value ='-3'>-3</option><option value ='-2'>-2</option><option value ='-1'>-1</option>";
        out +=                                    "<option value ='0'>0</option><option value ='1'>+1</option><option value ='2'>+2</option><option value ='3'>+3</option><option value ='4'>+4</option><option value ='5'>+5</option><option value ='6'>+6</option>";
        out +=                                    "<option value ='8'>+8</option><option value ='9'>+9</option><option value ='10'>+10</option><option value ='11'>+11</option><option value ='12'>+12</option>";
        out +=                                  "</select>"; 
        out +=                                  "<script type='text/javascript'> GMT.value ='" + String(Config.GMT)+"'; </script>"; 
        out +=              "<p>Дата:      " + ArrDayOfWeek[indexDayOfWeek] + "  " + String(date) + "  " + ArrMonth[indexMonth] + "  " + String(year);
        out +=              "<p>Время NTP:  <b><lable id=\"digitalWatch\" class= \"clock_script\"></lable></b> ";
    }
            
if (Config.SYNC_CLOCK == false)
    {
        out +=              "<p>Cинхронизировать время с NTP сервером? <input id=\"syncNTP\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"1\">Да";
        out +=                                                                     "<input id=\"syncNTP\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"0\" checked>Нет";
        out +=              "<p>Синхронизация отключена. Установите время вручную";
        
        out +=              "<p>Часовой пояс GMT <select id=\"GMT\" onchange=\"check();\" name=\"timezone\">";
        out +=                                    "<option value ='-12'>-12</option><option value ='-11'>-11</option><option value ='-10'>-10</option><option value ='-9'>-9</option><option value ='-8'>-8</option><option value ='-7'>-7</option>";
        out +=                                    "<option value ='-6'>-6</option><option value ='-5'>-5</option><option value ='-4'>-4</option><option value ='-3'>-3</option><option value ='-2'>-2</option><option value ='-1'>-1</option>";
        out +=                                    "<option value ='0'>0</option><option value ='1'>+1</option><option value ='2'>+2</option><option value ='3'>+3</option><option value ='4'>+4</option><option value ='5'>+5</option><option value ='6'>+6</option>";
        out +=                                    "<option value ='8'>+8</option><option value ='9'>+9</option><option value ='10'>+10</option><option value ='11'>+11</option><option value ='12'>+12</option>";
        out +=                                  "</select>"; 
        
        out +=                           "<p><label>Дата</label>";
        out +=                           "<p><select id=\"dayOfWeek\" onchange=\"check();\" name='dayOfWeek'>";
        out +=                           "<option value = '0'>Mon</option><option value = '1' >Tue</option><option value = '2' >Wed</option><option value = '3' >Thu</option><option value = '4' >Fri</option><option value = '5' >Sat</option><option value = '6' >Sun</option>";
        out +=                           "</select>";
        out +=                           "<select id=\"date\" onchange=\"check();\" name='date'>";
        out +=                              "<option value = '1'>1</option>  <option value = '2'>2</option>  <option value = '3'>3</option>  <option value = '4'>4</option>  <option value = '5'>5</option>  <option value = '6'>6</option>  <option value = '7'>7</option>  <option value = '8'>8</option>  <option value = '9'>9</option>";
        out +=                              "<option value = '10'>10</option><option value = '11'>11</option><option value = '12'>12</option><option value = '13'>13</option><option value = '14'>14</option><option value = '15'>15</option><option value = '16'>16</option><option value = '17'>17</option><option value = '18'>18</option><option value = '19'>19</option>";
        out +=                              "<option value = '20'>20</option><option value = '21'>21</option><option value = '22'>22</option><option value = '23'>23</option><option value = '24'>24</option><option value = '25'>25</option><option value = '26'>26</option><option value = '27'>27</option><option value = '28'>28</option><option value = '29'>29</option>";
        out +=                              "<option value = '30'>30</option><option value = '31'>31</option>";
        out +=                           "</select>";
        out +=                           "<select id=\"month\" onchange=\"check();\" name='month'>";
        out +=                              "<option value = '0'>Jan</option><option value = '1'>Feb</option><option value = '2'>Mar</option><option value = '3'>Apr</option><option value = '4'>May</option><option value = '5'>Jun</option><option value = '6'>Jul</option><option value = '7'>Aug</option><option value = '8'>Sep</option><option value = '9'>Oct</option><option value = '10'>Nov</option><option value = '11'>Dec</option>";
        out +=                           "</select>";
        out +=                           "<select id=\"year\" onchange=\"check();\" name='year'>";
        out +=                               "<option value='2020'>2020</option><option value='2021'>2021</option><option value='2022'>2022</option><option value='2023'>2023</option><option value='2024'>2024</option><option value='2025'>2025</option><option value='2026'>2026</option><option value='2027'>2027</option>";
        out +=                               "<option value='2028'>2028</option><option value='2029'>2029</option><option value='2030'>2030</option><option value='2031'>2031</option><option value='2032'>2032</option><option value='2033'>2033</option><option value='2034'>2034</option><option value='2035'>2035</option>";
        out +=                               "<option value='2036'>2036</option><option value='2037'>2037</option><option value='2038'>2038</option><option value='2039'>2039</option><option value='2040'>2040</option><option value='2041'>2041</option><option value='2042'>2042</option><option value='2043'>2043</option>";
        out +=                               "<option value='2044'>2044</option><option value='2045'>2045</option><option value='2046'>2046</option><option value='2047'>2047</option><option value='2048'>2048</option><option value='2049'>2049</option><option value='2050'>2050</option>";
        out +=                           "</select>";
        out +=                           "<p><label>Время</label>";
        out +=                           "<p><select id=\"hours\" onchange=\"check();\" name='hh'>";
        out +=                              "<option value = '0'>0</option><option value = '1'>1</option><option value = '2'>2</option><option value = '3'>3</option><option value = '4'>4</option><option value = '5'>5</option><option value = '6'>6</option><option value = '7'>7</option><option value = '8'>8</option><option value = '9'>9</option>";
        out +=                              "<option value = '10'>10</option><option value = '11'>11</option><option value = '12'>12</option><option value = '13'>13</option><option value = '14'>14</option><option value = '15'>15</option><option value = '16'>16</option><option value = '17'>17</option><option value = '18'>18</option><option value = '19'>19</option>";
        out +=                              "<option value = '20'>20</option><option value = '21'>21</option><option value = '22'>22</option><option value = '23'>23</option>";
        out +=                           "</select>";
       
        out +=                           "<select id=\"minutes\" onchange=\"check();\" name='mm'>";
        out +=                              "<option value = '0'>0</option>  <option value = '1'>1</option>  <option value = '2'>2</option>  <option value = '3'>3</option>  <option value = '4'>4</option>  <option value = '5'>5</option>  <option value = '6'>6</option>  <option value = '7'>7</option>  <option value = '8'>8</option>  <option value = '9'>9</option>";
        out +=                              "<option value = '10'>10</option><option value = '11'>11</option><option value = '12'>12</option><option value = '13'>13</option><option value = '14'>14</option><option value = '15'>15</option><option value = '16'>16</option><option value = '17'>17</option><option value = '18'>18</option><option value = '19'>19</option>";
        out +=                              "<option value = '20'>20</option><option value = '21'>21</option><option value = '22'>22</option><option value = '23'>23</option><option value = '24'>24</option><option value = '25'>25</option><option value = '26'>26</option><option value = '27'>27</option><option value = '28'>28</option><option value = '29'>29</option>";
        out +=                              "<option value = '30'>30</option><option value = '31'>31</option><option value = '32'>32</option><option value = '33'>33</option><option value = '34'>34</option><option value = '35'>35</option><option value = '36'>36</option><option value = '37'>37</option><option value = '38'>38</option><option value = '39'>39</option>";
        out +=                              "<option value = '40'>40</option><option value = '41'>41</option><option value = '42'>42</option><option value = '43'>43</option><option value = '44'>44</option><option value = '45'>45</option><option value = '46'>46</option><option value = '47'>47</option><option value = '48'>48</option><option value = '49'>49</option>";
        out +=                              "<option value = '50'>50</option><option value = '51'>51</option><option value = '52'>52</option><option value = '53'>53</option><option value = '54'>54</option><option value = '55'>55</option><option value = '56'>56</option><option value = '57'>57</option><option value = '58'>58</option><option value = '59'>59</option>";
        out +=                           "</select>";

        out +=                           "<select id=\"seconds\" onchange=\"check();\" name='ss'>";
        out +=                              "<option value = '0'>0</option>  <option value = '1'>1</option>  <option value = '2'>2</option>  <option value = '3'>3</option>  <option value = '4'>4</option>  <option value = '5'>5</option>  <option value = '6'>6</option>  <option value = '7'>7</option>  <option value = '8'>8</option>  <option value = '9'>9</option>";
        out +=                              "<option value = '10'>10</option><option value = '11'>11</option><option value = '12'>12</option><option value = '13'>13</option><option value = '14'>14</option><option value = '15'>15</option><option value = '16'>16</option><option value = '17'>17</option><option value = '18'>18</option><option value = '19'>19</option>";
        out +=                              "<option value = '20'>20</option><option value = '21'>21</option><option value = '22'>22</option><option value = '23'>23</option><option value = '24'>24</option><option value = '25'>25</option><option value = '26'>26</option><option value = '27'>27</option><option value = '28'>28</option><option value = '29'>29</option>";
        out +=                              "<option value = '30'>30</option><option value = '31'>31</option><option value = '32'>32</option><option value = '33'>33</option><option value = '34'>34</option><option value = '35'>35</option><option value = '36'>36</option><option value = '37'>37</option><option value = '38'>38</option><option value = '39'>39</option>";
        out +=                              "<option value = '40'>40</option><option value = '41'>41</option><option value = '42'>42</option><option value = '43'>43</option><option value = '44'>44</option><option value = '45'>45</option><option value = '46'>46</option><option value = '47'>47</option><option value = '48'>48</option><option value = '49'>49</option>";
        out +=                              "<option value = '50'>50</option><option value = '51'>51</option><option value = '52'>52</option><option value = '53'>53</option><option value = '54'>54</option><option value = '55'>55</option><option value = '56'>56</option><option value = '57'>57</option><option value = '58'>58</option><option value = '59'>59</option>";
        out +=                           "</select>";

                      
        out +=                           "<script type='text/javascript'> GMT.value ='"     + String(Config.GMT)     + "';";
        out +=                                                          " hours.value ='"   + String(hh)             + "';";
        out +=                                                          " minutes.value ='" + String(mm)             + "';";
        out +=                                                          " seconds.value ='" + String(ss)             + "';";
        out +=                                                          " dayOfWeek.value='"+ String(indexDayOfWeek) + "';";
        out +=                                                          " date.value='"     + String(date)           + "';";
        out +=                                                          " month.value='"    + String(indexMonth)     + "';";
        out +=                                                          " year.value='"     + String(year)           + "';";
        out +=                           "</script>";
    }
out +=              "<div class=\"button_submit\">";  
out +=                  "<button style=\"height: 40px; width: 100px;\" id=\"save\" disabled=\"disabled\">Сохранить</button>";
out +=              "</div>";
out +=        "</form>";
out +=      "</div>";
out +="</div>";
out +="</body>";
out +="</html>";
return (out);
delay(10);
}
