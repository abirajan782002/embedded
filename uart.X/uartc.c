

#include <xc.h>

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

void lcdcmd (unsigned char a)
{
    RC0=0; //RS=0
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=1000;i++);
    RC2=0;
    //for(int i=0;i<=5000;i++);
}


void uart_tx(unsigned char a)
{
  
    TXREG=a;
    while(TXIF==0);
    TXIF=0;
}

char uart_rx()
{
    while(RCIF==0);
    RCIF=0;
    return (RCREG);
}

void data (unsigned char a)
{
    RC0=1; //RS=0
    RC1=0;
    PORTD=a;
    RC2=1;
    for(int i=0;i<=1000;i++);
    RC2=0;
    //for(int i=0;i<=5000;i++);
}

void display(const char *p)
{
    while(*p)
    {
        uart_tx(*p);
        p++;
    }
}

void main(void) 
{
    TRISC=0x80;
    TRISD=0x00;
    
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=129;
    
    ADCON1=0X0F;
    TRISB=0xF0;
    TRISA=0x00;
    
    lcdcmd(0x01);
    lcdcmd(0x0f);
    lcdcmd(0x38);
    lcdcmd(0x06);
    char a;
    int i;
    while(1)
    {
    
    a=uart_rx();
    //uart_tx(a);
    
    if(a=='*')
    {
        while(1)
        {
            a=uart_rx();
            if(a=='#')
            {
                break;   
            }
            else
            {
                uart_tx(a);
            }
            
        }
            
        }
    }
    
    return;
}
