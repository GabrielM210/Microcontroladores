/*
 * File:   LAB3.c
 * Author: LAPTOP
 *
 * Created on 11 de septiembre de 2020, 10:06 PM
 */


#include <xc.h>
#define _XTAL_FREQ 4000000
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
int x;
int estado=0;
void dig2(void);
void main(void) {

    ADCON1bits.PCFG=0xF;
    INTCON2bits.NOT_RBPU=0;
    TRISB=0b11110000;
    PORTB=0b00001111;
    TRISD=0x00;
    PORTD=0X00;
    TRISC=0x00;
    PORTC=0x00;
    
    INTCONbits.GIE=1;
    INTCONbits.RBIE=1;
    INTCONbits.RBIF=0;
    
    while(1){
        PORTB=0b11111110;
        PORTB=0b11111101;
        PORTB=0b11111011;
        PORTB=0b11110111;
       
    }
    return;
}
void __interrupt() IN(void){
    PORTD=0x00;
    PORTC=0x00;
    estado=0;
    int x;
    if(PORTBbits.RB0==0 ){
        __delay_ms(100);
        if(PORTBbits.RB4==0)
        {PORTD=1;
        estado=1;}
        if(PORTBbits.RB5==0)
        {PORTD=4;
        estado=1;}
        if(PORTBbits.RB6==0)
        {PORTD=7;
        estado=1;}
       
       __delay_ms(100);
    }
    if(PORTBbits.RB1==0  ){
        if(PORTBbits.RB4==0)
        {PORTD=2;
        }
        if(PORTBbits.RB5==0)
        {PORTD=5;
        }
        if(PORTBbits.RB6==0)
        {PORTD=8;
        }
        if(PORTBbits.RB7==0)
        {PORTD=0;
        }
        
        __delay_ms(100);
    }
    if(PORTBbits.RB2==0  ){
        if(PORTBbits.RB4==0)
        {PORTD=3;
        }
        if(PORTBbits.RB5==0)
        {PORTD=6;
       }
        if(PORTBbits.RB6==0)
        {PORTD=9;
        }
       
        __delay_ms(100);
    }

   x=PORTD;

    
   
if(PORTBbits.RB0==0 ){
        if(PORTBbits.RB4==0)
        {PORTC=1;
       ;}
        if(PORTBbits.RB5==0)
        {PORTC=4;}
        if(PORTBbits.RB6==0)
        {PORTC=7;}
        
        __delay_ms(100);
    }
    if(PORTBbits.RB1==0 ){
        if(PORTBbits.RB4==0)
        {PORTC=2;}
        if(PORTBbits.RB5==0)
        {PORTC=5;}
        if(PORTBbits.RB6==0)
        {PORTC=8;}
        if(PORTBbits.RB7==0)
        {PORTC=0;}
         
        __delay_ms(100);
    }
    if(PORTBbits.RB2==0 ){
        if(PORTBbits.RB4==0)
        {PORTC=3;}
        if(PORTBbits.RB5==0)
        {PORTC=6;}
        if(PORTBbits.RB6==0)
        {PORTC=9;}
        
        __delay_ms(100);
    }
    do{INTCONbits.RBIF=0; }
while(PORTBbits.RB4==0||PORTBbits.RB5==0||PORTBbits.RB6==0||PORTBbits.RB7==0);
}
