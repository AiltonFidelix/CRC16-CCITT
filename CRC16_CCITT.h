/*
Autor: Ailton Fidelix
Data: 12/01/2021
Revisão: 1.0.0
https://github.com/AiltonFidelix/CRC16-CCITT-Xmodem.git
*/
#ifndef CRC16_CCITT_h
#define CRC16_CCITT_h

#include <Arduino.h>              // Inclui biblioteca Arduino.h para utilizar funções da IDE Arduino

class CRC16_CCITT{
	public:
		CRC16_CCITT();
		uint16_t calculate_crc(String dataString);       // Método de calculo CRC
		
	private:                                             //Métodos privados
		uint16_t calc_crc(char msg[],int n);
		uint16_t crc_xmodem_update(uint16_t crc, uint8_t data);
};

#endif
