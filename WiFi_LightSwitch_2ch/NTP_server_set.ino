void SNTP_server_set(){
  sntp_stop();
  sntp_setservername(0,"ntp.time.in.ua");
  sntp_setservername(1,"pool.ntp.org");
  sntp_setservername(2,"192.168.3.1");
  sntp_set_timezone(Config.GMT);
  sntp_init();
  delay (1000);
}
