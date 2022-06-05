#ifndef _USART_H_
#define _USART_H_

void USART1_Init(uint16_t mhz);
void USART1_Send_Byte(unsigned char ucSend_Data);
unsigned char USART1_Receive_Byte(void);
void USART1_Send_String(char *pucString);
void USART1_Send_uInt(uint32_t number);

#endif
