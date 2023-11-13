/*
 * File:   pin_manager.c
 * Author: Piet Motokolo
 *
 *
 */

#include "main_system_header.h"

void pin_init(void){
 /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x00;       //
    TRISB = 0x00;       //
    TRISC = 0x10;

    /**
    ANSELx registers
    */
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x50;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONB = 0x00;
    SLRCONC = 0X00;

    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLB = 0xF0;
    INLVLC = 0xF0;

    
    //I2C1SDAPPS = 0x0C;      //RB4->I2C1:SDA1;    
    //RB6PPS = 0x21;          //RB6->I2C1:SCL1;    
    RC7PPS = 0x10;          //RC7->UART1:TX1;     
    //RB4PPS = 0x22;          //RB4->I2C1:SDA1;    
    //U1RXPPS = 0x0D;         //RB5->UART1:RX1;    
    U1RXPPS = 0x14;         //RC4->UART1:RX1;
    //I2C1SCLPPS = 0x0E;      //RB6->I2C1:SCL1;    
    
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA2 = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC7 = 0;
    TRISCbits.TRISC4 = 1;
}

