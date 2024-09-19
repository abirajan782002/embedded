

#include <xc.h>

void main(void) 
{
    ADCON1=0x0f;
    TRISB=0xFF;
    TRISC=TRISD=0x00;
    INTCON=0xC0;
    INTCON3=0x08;
    
    
    while(1)
    {
       PORTC=0XFF;
       for(long i=0;i<50000;i++);
       PORTC=0X00;
       for(long i=0;i<50000;i++);
       
    }
    
    return;
}

void __interrupt() isr()
{
    if(INT1IF == 1)
    {
       PORTD=0X00;
       for(long i=0;i<50000;i++);
       PORTD=0X01;
       for(long i=0;i<50000;i++);
       PORTD=0X02;
       for(long i=0;i<50000;i++);
       PORTD=0X04;
       for(long i=0;i<50000;i++);
       PORTD=0X08;
       for(long i=0;i<50000;i++);
       PORTD=0X10;
       for(long i=0;i<50000;i++);
       PORTD=0X20;
       for(long i=0;i<50000;i++);
       PORTD=0X40;
       for(long i=0;i<50000;i++);
       PORTD=0X80;
       for(long i=0;i<50000;i++); 
       
    }
    INT0IF=0;
}
