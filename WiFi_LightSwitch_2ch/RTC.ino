void SyncRealTimeClock() {                                      //Функция инхронизации времени с NTP сервером
  String DOW, MON;
  byte sinc_count = 0;
  byte  n = 0;
  SNTP_server_set();
  label:
  //Time = sntp_get_current_timestamp();                        // получаем дату в UNIX формате
  String timefull = sntp_get_real_time(sntp_get_current_timestamp());  // получаем дату в виде dayweek month day 00:00:00 YYYY
  delay(2000);
  Serial.println("\n NTP Time: " + timefull);

  n =  timefull.indexOf(' ');                                   // ищем индекс первого вхождения 'пробела' в строке. это разделитель дня недели и месяца
  DOW = timefull.substring(n-3,n);                              // берем подстроку в которую запишутся три символа до 'пробела' (день недели)
    if (DOW == "Mon") indexDayOfWeek = 0;                       // определяем индекс дня недели
    if (DOW == "Tue") indexDayOfWeek = 1;
    if (DOW == "Wed") indexDayOfWeek = 2;
    if (DOW == "Thu") indexDayOfWeek = 3; 
    if (DOW == "Fri") indexDayOfWeek = 4; 
    if (DOW == "Sat") indexDayOfWeek = 5; 
    if (DOW == "Sun") indexDayOfWeek = 6; 

  MON = timefull.substring(n+1, n+4);                          // берем подстроку в которую запишутся три символа после 'пробела' (месяц)
    if (MON == "Jan") indexMonth = 0;                          // определяем индекс месяца
    if (MON == "Feb") indexMonth = 1;
    if (MON == "Mar") indexMonth = 2;
    if (MON == "Apr") indexMonth = 3; 
    if (MON == "May") indexMonth = 4; 
    if (MON == "Jun") indexMonth = 5; 
    if (MON == "Jul") indexMonth = 6;
    if (MON == "Aug") indexMonth = 7; 
    if (MON == "Sep") indexMonth = 8; 
    if (MON == "Oct") indexMonth = 9; 
    if (MON == "Nov") indexMonth = 10;
    if (MON == "Dec") indexMonth = 11;

  
  date = timefull.substring(n+5, n+7).toInt();                  // берем подстроку в которую запишется число месяца
  n = timefull.indexOf(':');                                    // ищем индекс первого вхождения ":" в строке. это разделитель часов и минут
  hh = timefull.substring(n - 2, n).toInt();                    // берем подстроку в которую запишутся два символа до : (часы) и конвертируем в число
  mm = timefull.substring(n+1, n+3).toInt();                    // берем подстроку в которую запишутся два символа после : (мнуты) и конвертируем в число
  
  n = timefull.lastIndexOf(':');                                // ищем индекс последнего вхождения ":" в строке. это разделитель минут и секунд                     
  ss = timefull.substring(n+1, n+3).toInt();                    // берем подстроку в которую запишутся два символа после : (скунды) и конвертируем в число
  
  n = timefull.length();                                        // получаем длину строки
  year = timefull.substring(n-5, n).toInt();                    // берем подстроку в которую запишутся два последих символа строки (год) и конвертируем в число
  sinc_count++;
  while (hh == 0 + Config.GMT & mm == 0 & sinc_count < 10)      // 10 попыток синхронизации времени (если неуданая, то получает время 08 часов 00 минут)
        {
          goto label;
        }
  Serial.println("Попыток связи с NTP " + String(sinc_count));

}

void clock_()                                                   //функция отсчета времени для часов если использовать <Ticker.h> и нет RTC модуля
{                                                               //раскоментировать функцию и закоментировать строку 84
  ss++;
  if (ss>59)
      {
        ss = 0;
        mm++;
        if (mm > 59)
            {
              mm = 0;
              hh++;
              if(hh > 23) 
                 {
                    hh = 0;
                    date ++;
                            if (( date > 31 ) && ( indexMonth == 0 || indexMonth == 2 || indexMonth == 4 || indexMonth == 6 || indexMonth == 7 || indexMonth == 9 || indexMonth == 11 ))
                                {
                                  date = 1;
                                  indexMonth++;
                                  if (indexMonth > 11)
                                      {
                                        indexMonth = 0;
                                      }
                                }
                            if (( date > 30 ) && ( indexMonth == 3 || indexMonth == 5 || indexMonth == 8 || indexMonth == 10 ))
                                {
                                  date = 1;
                                  indexMonth++;
                                }
                            if (( date > 29) && (indexMonth == 1 )) 
                                {
                                  date = 1;
                                  indexMonth++;
                                } 
                            if (( indexMonth == 1 ) && ( date > 28) && (year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
                                {
                                  date = 29;
                                  indexMonth++;
                                }         
                    
                    indexDayOfWeek++;
                    if (indexDayOfWeek > 6)
                        {
                          indexDayOfWeek = 0;
                        }
                 }
            }
      }
}
