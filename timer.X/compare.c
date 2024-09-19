/*
 * File:   compare.c
 * Author: ESDC
 *
 * Created on 29 August, 2024, 9:56 AM
 */


#include <xc.h>

void main(void) 
{
    
    TRISC=0x00;
    
    T1CON=0x31;
    CCP1CaON=0x02;
    CCPR1L=10;
    CCPR1H=20;
    while(1);
    return;
}
