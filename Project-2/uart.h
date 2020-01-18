#include "uart.c"

int UART2Configure(int desired_baud);
int SerialTransmit(const char *buffer);
unsigned int SerialReceive(char *buffer, unsigned int max_size);
int _mon_getc(int canblock);