/*
 * File:   newmain.c
 * Author: ESDC
 *
 * Created on 26 July, 2024, 8:53 AM
 */


#include <xc.h>

void delay(long i)
{
    for(i=0;i<100000;i++);
}

void main(void) 
{
        TRISC=0XFF;
        TRISD=0X00;
        TRISA=0X00;
        int count1 =0,count2 = 0 ;
        
        
    while(1)
    {   
        if( RC0 == 0 && count1 == 0)
        {
         RD0=  0 ;RD1 = 1 ;
         count1=1;
         while(RC0==0);
        }
        
        if( RC0 == 0 && count1 == 1)
        {
        RD0=  1 ;RD1 = 0 ;
        count1=2;
        while(RC0==0);

        }
        
        if( RC0 == 0 && count1 == 2)
        {
        RD0=  0 ;RD1 = 0 ;
        count1=0;
        while(RC0==0);

        }
        
        ///////////////////////////
        
        
         if( RC3 == 0 && count2 == 0)
        {
         RD2=  0 ;RD3 = 1 ;
         count2=1;
         while(RC3==0);
        }
        
        if( RC3 == 0 && count2 == 1)
        {
        RD2=  1 ;RD3 = 0 ;
        count2=2;
        while(RC3==0);

        }
        
        if( RC3 == 0 && count2 == 2)
        {
        RD2=  1 ;RD3 = 1 ;
        count2 =0;
        while(RC3==0);

        }
    }
    return;
}
