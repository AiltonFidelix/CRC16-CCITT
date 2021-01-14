/*
Autor: Ailton Fidelix
Data: 12/01/2021
Revisão: 1.0.0
https://github.com/AiltonFidelix/CRC16-CCITT-Xmodem.git
*/
#include <CRC16_CCITT.h>     // Inclui o biblioteca crc16-ccitt

CRC16_CCITT CRC;

//Método string para char array para calculo do CRC
uint16_t CRC16_CCITT::calculate_crc(String dataString)
{
  int n = dataString.length()+1; // Pega tamanho da string

  char bufferChar[n];  //Cria char array
  
  dataString.toCharArray(bufferChar,n); //Converte string em char array
  
  return calc_crc(bufferChar,n-1); //Retorna o CRC da string
}

//Método cálculo CRC
uint16_t CRC16_CCITT::calc_crc(char msg[],int n)
{
  // Valor inicial. xmodem usa 0xFFFF, mas este exemplo
  // requer um valor inicial de zero.
  uint16_t x = 0;
  
  int y = 0; //Index buffer char
  
  while(n>0) {
	n--;
    x = crc_xmodem_update(x, (uint16_t)msg[y]);
	y++;
  }
  return(x);
}

//Método CRC update
// Polynomial: x^16 + x^12 + x^5 + 1 (0x1021)
uint16_t CRC16_CCITT::crc_xmodem_update(uint16_t crc, uint8_t data)
{
  int i;

  crc = crc ^ ((uint16_t)data << 8);
  for (i=0; i<8; i++) {
    if (crc & 0x8000)
      crc = (crc << 1) ^ 0x1021; //(polynomial = 0x1021)
    else
      crc <<= 1;
  }
  return crc;
}