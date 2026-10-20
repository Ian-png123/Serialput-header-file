#include <avr/io.h>

void usart_init(unsigned int ubrr)
{
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    //enable the rx and tx pins
    UCSR0B = (1 << RXEN0) | ( 1 << TXEN0);
    // set frame format to 8 data bits and 1 stop bit no parity(checking for errors)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
int uart_putchar(char c){
    while(!(UCSR0A & (1 << UDRE0))){;}
    UDR0 = c;
    return 0;
}
unsigned char uart_recv(void){
    while(!(UCSR0A & (1 << RXC0))){ ; }
    return UDR0;

}
void putln(const char *String){
    while(*String)
    {
        uart_putchar(*String++);
    }
    uart_putchar('\r'); // Carriage return
    uart_putchar('\n'); 
}
void putf(const char *words){
    while(*words)
    {
        uart_putchar(*words++);
    }

}
