
#include "main_system_header.h"

void uart_init(void)
{
    U1BRG = 0x0340; //832 decimal Baud rate 19200
    U1CON0bits.BRGS = 1; //HIGH speed generator
    U1CON0bits.ABDEN = 0; //auto baud detect is off  

    U1CON0bits.MODE = 0x00; //Asynchronous 8-bit mode


    U1CON1bits.WUE = 0; //wakeup disable
    U1CON1bits.RXBIMD = 0; //set rxbkif on rising input
    U1CON1bits.BRKOVR = 0; //Output is driven by the tx shift register
    U1CON1bits.SENDB = 0; //Break transmission is disabled

    U1CON2bits.RUNOVF = 0; //rx input shifter continues after overflow
    U1CON2bits.RXPOL = 0; //rx polarity not inverted
    U1CON2bits.STP = 0x00; //transmit 1 stop bit
    U1CON2bits.C0EN = 0; //Checksum is disabled
    U1CON2bits.TXPOL = 0; //output data is not inverted
    U1CON2bits.FLO = 0x00; //flow control is off

    U1FIFO = 0x00;
    U1UIR = 0x00;
    U1ERRIR = 0x00; //UART Error interrupt flag register
    U1ERRIE = 0x00; //UART transmit shift register empty interrupt on

    PIE4bits.U1IE = 1; //enable uart1 interrupt
    PIE4bits.U1EIE = 0; //framing error interrupt disable
    /********Main Loop Does not execute when U1TXIE is enabled, I do not know why yet*/
    PIE4bits.U1TXIE = 0; //transmit interrupt enable 
    PIE4bits.U1RXIE = 1; //receive interrupt enable
    PIR4 = 0x00; //Clear all the interrupt flags
    IPR4bits.U1TXIP = 0; //Make transmitter interrupt high priority
    IPR4bits.U1RXIP = 1; //Make receiver interrupt low priority
    IPR4bits.U1IP = 1; //uart_1 interrupt is high priority*/

    U1CON0bits.TXEN = 1; //enable transmit
    U1CON0bits.RXEN = 1; //enable receive
    U1CON1bits.ON = 1; //Serial Port Enabled
}

void uart_transmit(uint8_t *c)
{
    while (PIR4bits.U1TXIF == 0);
    U1TXB = *c;
}


void uart_write(uint8_t *c)
{
    while (*c != '\0')
    {
        uart_transmit(c);
        c++;
    }
}

bool uart_rx_ready(void){
    return (bool)(PIR4bits.U1RXIF);
}

uint8_t uart_read(void){
   while(!PIR4bits.U1RXIF){
   }
    return U1RXB;
}

#if 0
void uart_read1(void){
    uint8_t i = 0;
    for(i = 0; i <= 50 ;i++){
        while(!PIR4bits.U1RXIF);
        Dynamic_string[i] = U1RXB;
    }
    Dynamic_string[50] = '\0';
}
#endif 

