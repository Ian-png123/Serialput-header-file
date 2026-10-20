#ifndef SER_LNK_H
#define SER_LNK_H

void usart_init(unsigned int myUbrr);
unsigned char uart_recv(void);
int uart_putchar(char c);
void putf(const char *words);
void putln(const char *String);


#endif
