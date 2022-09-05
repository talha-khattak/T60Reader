#include <Wire.h>

 byte eeprom_addr [] = {84 , 85 , 86 , 87};    

void setup () { 
  Serial.begin(9600);
  Wire.begin(); 
  Wire.setClock(10000); // sketch runs at standard IIC speed as well, it's not necessary   
  
  int addr = 0 ;
  int i = 0; 
  
  for( int i = 0 ; i < 4 ; i ++){ 
    Wire.beginTransmission(eeprom_addr[i]); 
    Wire.write(0); 
  }

  byte error = Wire.endTransmission(); 
  if (error ==  0) { 
    for (int j = 0 ; j < 8 ; j ++){ 
      Serial.print(addr, HEX); 
    Serial . print ( ":" ); 
    Wire.requestFrom(eeprom_addr[i], 16 ); 
    while(Wire.available()) { 
            byte c = Wire.read(); 
            Serial.print(c , HEX); 
            Serial.print("");
           } 
        Serial . println (); 
        addr += 16; 
      
    } 
    
  } 
        else { 
        Serial . print (
        eeprom_addr[i], HEX ); 
        Serial.println("not answered"); 
      } 
      
  
} 
      
void loop () { 
  
  } 
