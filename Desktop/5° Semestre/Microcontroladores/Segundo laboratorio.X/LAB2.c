/*
 * File:   lab2.c
 * Author: Gabriel M
 *
 * Created on 22 de agosto de 2020, 04:35 PM
 */


#include <xc.h>

#pragma config FOSC= XT_XT
#pragma config CPUDIV= OSC1_PLL2

void main(void) {
     TRISA=1;
     TRISD=0b00101010;
     TRISC=0b00000000;
     ADCON0=0b0000;
     ADCON1bits.PCFG=0b00000000;
     ADCON1bits.VCFG0=0;    
     ADCON1bits.VCFG1=0;
     ADCON2bits.ACQT=2;
     ADCON2bits.ADCS=4;
     ADCON2bits.ADFM=0;
     
     ADCON0bits.ADON=1;
     while(1){
         ADCON0bits.GO_DONE=1;
         while(ADCON0bits.GO_DONE==1){
         
             float conv=ADRESH;
             double x;
             double conv2;
             
             conv2= ( 100.0*conv*5.0)/255.0;
             x= (conv2*1.8)+32;
             
             if(x>176){
                 if(PORTDbits.RD1==1&&PORTDbits.RD3==1){
                     PORTDbits.RD0=1;
                 
                 
                 
                 }
                 else if(PORTDbits.RD5==1){
                     PORTDbits.RD0=1;
             
             }
                 else{
                  PORTDbits.RD0=0;
                 }
                 if (PORTDbits.RD1==1&&PORTDbits.RD5==1){ 
                     PORTDbits.RD0=0;
                 }
                 if (PORTDbits.RD3==1&&PORTDbits.RD5==1){ 
                     PORTDbits.RD0=0;
                 }
                    
                     
             }
             else if(x<176){
                 if (PORTDbits.RD1==1&&PORTDbits.RD5==1){ 
                     PORTDbits.RD0=1;
                 }
                 else if(PORTDbits.RD3==1){
                  PORTDbits.RD0=1;
             }
                 else{
                 PORTDbits.RD0=0;
                 }
             if (PORTDbits.RD1==1&&PORTDbits.RD3==1){ 
                     PORTDbits.RD0=0;
                 }
                 if (PORTDbits.RD3==1&&PORTDbits.RD5==1){ 
                     PORTDbits.RD0=0;
                 }
             }
         }
     }
    
     
    return;
}
