void Convert (char massiv []){
  
  uint8_t point_index[3] = {};
  uint8_t n = 0;
  String address = "";
  for (int i = 0; i < 16; i++)
  {
    address += String(massiv[i]);
    if (massiv[i] == '.'){
       point_index[n] = i;
       n++;}
  }
 address = "";
   
for (int i = 0; i < point_index[0]; i++ ){
  address += String(massiv[i]); 
}
first_oct = address.toInt();
  address = "";
  
for (int i = point_index[0]+1; i < point_index[1]; i++){
 address += String(massiv[i]);
}
second_oct = address.toInt();
address = "";

for (int i = point_index[1]+1; i < point_index[2]; i++){
 address += String(massiv[i]);
}
third_oct = address.toInt();
address = "";

for (int i = point_index[2]+1; i < 16; i++){
 address += String(massiv[i]);
}
fourth_oct = address.toInt();
address = "";

}
