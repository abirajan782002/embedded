/*
 * File:   segmentt.c
 * Author: ESDC
 *
 * Created on 30 August, 2024, 9:25 AM
 */


#include <xc.h>
void delay()
{
    for(long i=0;i<1000;i++);
}

void main(void) 
{
    TRISC=0x00;
    TRISD=0x00;
    PORTB=0xff;
    
    int i,j;
  
    unsigned char a[10]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} , b[4]={ 0x0E,0x0D,0x0B,0x07} ;

    while(1)
    {
    for(int n1=0;n1<10;n1++)
    {
        
        for(int n2=0;n2<10;n2++)
        {
            
            for(int n3=0;n3<10;n3++)
            {
 
                for(int n4=0;n4<10;n4++)
                {
                    while(1)
                    {
                        
                    PORTD=b[3];
                    PORTC=a[n4];
                                      delay();
  
                    PORTD=b[2];
                    PORTC=a[n3];
                                      delay();
  
                    PORTD=b[1];
                    PORTC=a[n2];
                                      delay();
  
                    PORTD=b[0];
                    PORTC=a[n1];
                    delay();
                     
                     if ( RB7==1)
                     {   //while(RB7==1);
                         delay();
                         break;
                     }
                    }
                    
                   
                }
                
                
            }

        }
    }
    }
    
    return;
}
