/*
 * File:   lcd.c
 * Author: ESDC
 *
 * Created on 2 August, 2024, 9:39 AM
 */


#include <xc.h>
#include <string.h>
// CONFIG1H
#pragma config OSC = IRCIO67 
void lcdcmd (unsigned char a)
{
    RC0=0; //RS=0
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=5000;i++);
}

void data (unsigned char a)
{
    RC0=1; //RS=0
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=100;i++);
    RC2=0;
    for(int i=0;i<=1000;i++);
}
void display(const char *p)
{
    while(*p)    
    {
       data(*p);
       p++;
    }
}

unsigned char keypad()
{
    while(1)
    {
    PORTB=0X0E;
        if(RB4==0)
        {
            return '1';
        }
        else if(RB5==0)
        {
            return '2';
        }
        else if(RB6==0)
        {
            return '3';
        }
        else if(RB7==0)
        {
            return '4';
        }
        PORTB=0X0D;
        if(RB4==0)
        {
            return '5';
        }
        else if(RB5==0)
        {
            return '6';
        }
        else if(RB6==0)
        {
            return '7';
        }
        else if(RB7==0)
        {
            return '8';        
        }
        PORTB=0X0B;
        if(RB4==0)
        {
            return '9';
        }
        else if(RB5==0)
        {
            return '0';
        }
        else if(RB6==0)
        {
            //return 'a';
        }
        else if(RB7==0)
        {
            //return 'b';
            
        }
       PORTB=0X07;
       if(RB4==0)
        {
           //return 'c';
        }
        else if(RB5==0)
        {
           // return 'd';
        }
        else if(RB6==0)
        {
            //return 'e';
        }
        else if(RB7==0)
        {
           return 'r';
            
        }
    }
}


void main(void) 
{
    ADCON1=0X0F;
    TRISB=0xF0;
    TRISA=0x00;
    TRISC=TRISD=0x00;
    lcdcmd(0x01);
    lcdcmd(0x0f);
    lcdcmd(0x38);
    unsigned char s,a[]="0000",pass[]="1234",pass_temp1[]="0000",pass_temp2[]="0000";
    
    while(1)
    {
       lcdcmd(0x01);
       lcdcmd(0x80);
       display("enter pass");
       lcdcmd(0xc0);
            for(long j=0;j<4;j++)
            {
                s=keypad();
                while( RB4==0 ||  RB5==0 ||  RB6==0 ||  RB7==0 );
                a[j]=s;
                if(s=='r')
                {
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    display("enter old pass");
                    lcdcmd(0xC0);
                    for(int i=0;i<4;i++)
                    {
                        s=keypad();
                        data(s);
                        a[i]=s;
                    }
                    if(strcmp(a,pass)!=0)
                    {
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    display("wrong pass");
                    for(long i=0;i<5000;i++);
                    break;
                    }
                    
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    display("enter new pass");
                    lcdcmd(0xC0);
                    for(int i=0;i<4;i++)
                    {
                        s=keypad();
                        data(s);
                        pass_temp1[i]=s;
                    }
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    display("enter again");
                    lcdcmd(0xC0);
                    for(int i=0;i<4;i++)
                    {
                        s=keypad();
                        data(s);
                        pass_temp2[i]=s;
                    }
                    
                    if(strcmp(pass_temp1,pass_temp2)==0)
                    {
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    strcpy(pass,pass_temp1);
                    display("pass set");
                    for(long i=0;i<5000;i++);
                    break;
                    }
                    else
                    {
                    lcdcmd(0x01);
                    lcdcmd(0x80);
                    display("entry mismatch");
                    for(long i=0;i<5000;i++);
                    break;
                    }
                }
                
                data(s);
                
                if(j==3)
                {
                    if(strcmp(a,pass)==0)
                    {
                        lcdcmd(0x01);
                        lcdcmd(0x80);
                        display("correct pass");
                        for(long i=0;i<5000;i++);
                    }
                    else
                    {
                        lcdcmd(0x01);
                        lcdcmd(0x80);
                        display("wrong pass");
                        for(long i=0;i<5000;i++);  
                    }
                }
                
            }
    }
   
    return;
}
