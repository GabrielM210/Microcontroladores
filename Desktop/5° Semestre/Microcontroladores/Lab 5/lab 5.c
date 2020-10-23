/*
 * File:   lab 5.c
 * Author: Gabriel M
 *
 * Created on 16 de octubre de 2020, 09:34 PM
 */


#include <xc.h>

#pragma config FOSC= XT_XT
#pragma config CPUDIV= OSC1_PLL2
#define _XTAL_FREQ 4000000
#include "LCD.h"
#include <stdio.h>
void main(void) {
    char buffer_lcd[20];
      int z=0;
    TRISA=1;
    TRISD=0;
    TRISC=0b1;
    ADCON0=0b0000;
    
    ADCON1bits.PCFG=0b00000000;
    ADCON1bits.VCFG0=0;   
    ADCON1bits.VCFG1=0;
    ADCON2bits.ACQT=2;
    ADCON2bits.ADCS=4;
    ADCON2bits.ADFM=0;
    ADCON0bits.ADON=1;
    lcd_init();
     while(1){
         
       
         ADCON0bits.GO_DONE=1;
         while(ADCON0bits.GO_DONE==1){
             
         if (PORTCbits.RC0==0)
            
      
         {__delay_ms(100);
            z++;
         lcd_clear();
         }
         
             float conv=ADRESH;
             double x;
             double conv2;
             double k;
            
             conv2= ( 100.0*conv*5.0)/255.0;
             x = (conv2*1.8)+32;
             k = (conv2 + 273.15);
               lcd_gotoxy(1,1);
               if(z==0){
                  lcd_putc("la temperatura") ;
                 lcd_gotoxy(2,1);
               lcd_putc("es:");
               }
               if(z==1){
                   
               lcd_putc("Celcius");
               lcd_gotoxy(2,1);
              sprintf(buffer_lcd,"%03.0f",conv2);
               lcd_putc(buffer_lcd);
               
               }
               if(z==2){
                
               lcd_putc("farenheit");
               lcd_gotoxy(2,1);
               sprintf(buffer_lcd,"%03.0f",x);
               lcd_putc(buffer_lcd);
               }
               if(z==3){
                
               lcd_putc("kelvin");
               lcd_gotoxy(2,1);
               sprintf(buffer_lcd,"%03.0f",k);
               lcd_putc(buffer_lcd);
               
               }
               if(z==4){
                
                   z=0;
                   lcd_clear;
               
               }
               
             
            
           
         }
     }
    return;
}
