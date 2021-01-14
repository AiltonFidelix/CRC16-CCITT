/*
Autor: Ailton Fidelix
Data: 12/01/2021
Revisão: 1.0.0
https://github.com/AiltonFidelix/CRC16-CCITT-Xmodem.git
*/
#include <CRC16_CCITT.h>

String inputString = "123456789";    //CRC =  0x31C3

void setup() {
  // initialize serial:
  Serial.begin(115200);
  delay(1000);
  Serial.print("Priting CRC to input " + inputString + " = ");
  Serial.println(CRC.calculate_crc(inputString),HEX);  //Print CRC of input string
}

void loop(){
  //Do nothing
}
