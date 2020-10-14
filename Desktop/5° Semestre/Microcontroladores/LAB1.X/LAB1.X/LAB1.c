/*
 * File:   LAB1.c
 * Author: LAPTOP
 *
 * Created on 15 de agosto de 2020, 02:16 PM
 */

#include <xc.h>
#define _XTAL_FREQ 4000000
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))

void main(void) {
    int a,b,u,d,c;
ADCON1= 0XF0;
TRISA =0b1111;
TRISD=0;
TRISB=0;
TRISC=0;
T0CON=0XF8;
while(1){
    PORTB=0X0F;
    NOSON: PORTB =0xF0;
INICIO: TMR0L=0;
LEE: c=TMR0L/100;
	d=(TMR0L%100)/10;
	u=(TMR0L%100)%10;
PORTD = d*0X10+u;
    

goto LEE;
if(c==0&&d==1&&u==0){
    PORTBbits.RB0==0;
    goto DO;
}
if(c==0&&d==1&&u==0){
    PORTAbits.RA6==0;
    goto DO2;
}

}
    DO: for(b=0;b<20;b++){
        PORTD = 11;
        for(a=0;a<19;a++){
            TMR0L = 244;
            SENSA1: if(INTCONbits.TMR0IF==0)goto SENSA1;
            INTCONbits.TMR0IF=0;
        } 
        PORTD = 0;
        for(a=0;a<19;a++){
            TMR0L = 244;
            SENSA2: if(INTCONbits.TMR0IF==0)goto SENSA2;
            INTCONbits.TMR0IF=0;
        }
        
    }
    DO2: for(b=0;b<20;b--){
        PORTD = 1;
        for(a=0;a<19;a--){
            TMR0L = 244;
            SENSA1: if(INTCONbits.TMR0IF==0)goto SENSA1;
            INTCONbits.TMR0IF=0;
        } 
        PORTD = 0;
        for(a=0;a<19;a--){
            TMR0L = 244;
            SENSA2: if(INTCONbits.TMR0IF==0)goto SENSA2;
            INTCONbits.TMR0IF=0;
        }
        
    }
goto NOSON;
    return;
}