/*
 * File:   Blinky_test1.c
 * Author: Piet
 *
 */


#include "main_system_header.h"

#define LED_PIN    LATCbits.LATC1

void main(void) {
    OSCENbits.HFOEN = 1;            //ENable the internal high frequency oscillator
    OSCFRQ = 0x08;                  //select 64Mhz frequency
    while(OSCSTATbits.HFOR != 1);   //wait for the oscillator to be ready
    
    pin_init();
    uart_init();  
    
    INTCON0bits.GIEH = 0;           //enable high priority interrupts
    INTCON0bits.GIEL = 0;           //enable low priority interrupts
    
    INTCON0bits.IPEN = 1;           //disable priority level
    INTCON0bits.GIEH = 1;         //enable high priority interrupts
    INTCON0bits.GIEL = 1;         //enable low priority interrupts
    
   
    OUTPUT_EN = LOW;                //Output Enabler of the Shift registers
    CLEAR = HIGH;                   //Clear all registers
    LED_PIN = LOW;
    uart_write(Startup_string);
    
    while(1){
        //Check if the is data in the RX Buffer
        if(uart_rx_ready()){
            HeaderByte = uart_read();
            if(HeaderByte == ANIMATION_HEADER){  //Check if Header byte is received
                AnimationByte = uart_read();
                switch(AnimationByte){            //Check which animation is prompted
                    case ANIMATION_1:  
                        One_Led_Clockwise();
                        break;
                    case ANIMATION_2:
                        Draw_Circle();
                        break;
                    case ANIMATION_3:
                        Reverse_Circle();
                        break;
                    case ANIMATION_4:
                        break;
                    case ANIMATION_5:
                        break;
                    case ANIMATION_6:
                        break;
                    case ANIMATION_7:
                        break;
                    case ANIMATION_8:
                        break;
                    case ANIMATION_9:
                        break;
                    case ANIMATION_10:
                        break;
                    case ANIMATION_11:
                        break;
                    case ANIMATION_12:
                        break;
                    case ANIMATION_13:
                        break;
                    case ANIMATION_14:
                        break;    
                    default:
                        break;
                }
            }
            } 
    }//while
    
}//main



