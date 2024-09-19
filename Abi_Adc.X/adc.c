/*
 * File:   adc.c
 * Author: ESDC
 *
 * Created on 4 September, 2024, 9:53 AM
 */


#include <xc.h>
#include <stdio.h>

void lcdcmd (unsigned char a)
{
    RD0=0; //RS=0
    RD1=0;
    PORTC=a;
    RD2=1;
    for(int i=0;i<=1000;i++);
    RD2=0;
    //for(int i=0;i<=5000;i++);
}


void data (unsigned char a)
{
    RD0=1; //RS=0
    RD1=0;
    PORTC=a;
    RD2=1;
    for(int i=0;i<=1000;i++);
    RD2=0;
    //for(int i=0;i<=5000;i++);
}


void display(const char *p)
{
    while(*p)
    {
       data(*p);
        p++;
    }
}

void main(void) 
{
    TRISC=TRISD=0x00;
    PORTA=0xff;
    
   

    lcdcmd(0x01);
    lcdcmd(0x0E);
    lcdcmd(0x38);
    //lcdcmd(0x06);
    lcdcmd(0x86);
    ADCON2=0x86;
    ADCON1=0x00;
    lcdcmd(0x80);
    display("ADC1:");
    lcdcmd(0xc0);
    display("ADC2:");
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
        
        ADCON0=0x05;
        for(int i=0;i<100;i++);
        ADCON0=0x07;
        
        while(ADIF==0);
        ADIF=0;
        adc2=ADRES;
 
        sprintf(conv1,"%5d",adc1);sprintf(conv2,"%5d",adc2);
        
        
        lcdcmd(0x87);
        display(conv1);
        lcdcmd(0xc7);
        display(conv2);
        


    }
    
    return;
}
