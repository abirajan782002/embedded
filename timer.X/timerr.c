/*
 * File:   timerr.c
 * Author: ESDC
 *
 * Created on 26 August, 2024, 9:27 AM
 */


#include <xc.h>

#define fosc 20000000
#define del 0.01
#define max 65536
#define pre 16
#define POST 16
#define a (int) ( (fosc*del) / (4*pre*POST) );

void delay()
{
   
    while( TMR2IF ==0);
    TMR2IF=0;
}

void main(void) 
{
    T2CON=0x7E;
    PR2=a;
    TRISC=0x00;
    while(1)
    {
        PORTC=0x00;
        delay();
        PORTC=0xFF;
        delay();
    }
    return;
}
