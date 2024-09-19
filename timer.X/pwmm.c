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
    ADCON1=0x0f;
    T2CON=0x06;
    TRISC=0x00;
    TRISA=0xFF;
    PR2=255;
    CCP1CON=0x0C;
    CCPR1L=0x80;
    
    while(1)
    {
        if( RA2 == 1)
        {
            CCP1CON=0x0C;
            CCPR1L=0x40;
            while(RA2==1);
            
        }
        if(RA3 == 1)
        {
            CCP1CON=0x0C;
            CCPR1L=0x80;
            while(RA3==1);
        }
        if(RA4 == 1)
        {
            CCP1CON=0x3C;
            CCPR1L=0xBF;
            while(RA4==1);
            
        }
    }
    return;
}
