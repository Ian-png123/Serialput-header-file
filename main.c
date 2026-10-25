#define F_CPU     16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ser_lnk.h"

#define BAUD      9600
#define myUbrr    (F_CPU/16/BAUD - 1)

unsigned char readln(char *buff, unsigned char max)
{
    unsigned char i = 0;
    for(;;){
        unsigned char b = uart_recv();
        if(b == '\n' || b == '\r'){
            if(i == 0)continue;
            break;
        }
        if(i < max - 1){
            buff[i++] = b;
            uart_putchar(b);
        }
    }
    buff[i] = '\0';
    return i;
}
int main(void)
{
    char name[20] = {0}; 
    char word[20] = "HELLO FROM ARDUINO";
    usart_init(myUbrr);
    DDRB |= (1 << PB5);
    putf("BOOT OK\n");
    PORTB |= (1 << PB5);
    for(;;){
        putln("Press enter to reveal the line of text: ");
        uart_recv();
        putln(word);
        putf("Enter your name:");
        readln(name, sizeof(name));
        putf("Hello, "); putf(name); putf("!");
    }

    return 0;
}
