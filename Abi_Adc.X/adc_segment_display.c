/*
 * File:   adc_segment_display.c
 * Author: ESDC
 *
 * Created on 6 September, 2024, 9:54 AM
 */


#include <xc.h>
#include <stdio.h>
void delay()
{
    for(long i=0;i<1000;i++);
}
void seg(char s)
{
    unsigned char a[10]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} , b[4]={ 0x0E,0x0D,0x0B,0x07} ;
    switch(s)
    {
        case ' ': PORTC=a[0];
                  break;
        case '0': PORTC=a[0];
                  break;
        case '1': PORTC=a[1];
                  break;
        case '2': PORTC=a[2];
                  break;
        case '3': PORTC=a[3];
                  break;
        case '4': PORTC=a[4];
                  break;
        case '5': PORTC=a[5];
                  break;
        case '6': PORTC=a[6];
                  break;
        case '7': PORTC=a[7];
                  break;
        case '8': PORTC=a[8];
                  break;
        case '9': PORTC=a[9];
                  break;
             
    }
}
void main(void) 
{
    TRISC=0x00;
    TRISD=0x00;
    PORTB=0xff;
    PORTA=0xff;
    ADCON2=0x86;
    ADCON1=0x00;
    unsigned char a[10]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} , b[4]={ 0x0E,0x0D,0x0B,0x07} ;
    int i,j;
  
    

    while(1)
    {
        int adc1;
        int adc2;
        char conv1[15];
        char conv2[15];
        
        ADCON0=0x01;
        for(int i=0;i<100;i++);
        ADCON0=0x03;
        
        while(ADIF==0);
        ADIF=0;
        adc1=ADRES;
        
   
 
        sprintf(conv1,"%4d",adc1);
        
        for(i=0;i<100;i++)
        {
            for(int i=0;i<4;i++)
            {
                PORTD=b[i];
                seg(conv1[i]);
                delay();
            }
        }
        
        
        


    }
    return;
}
