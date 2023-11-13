
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
  
#ifndef UART_H
#define	UART_H

#include <xc.h> // include processor files - each processor file is guarded.  

void uart_init(void);
void uart_transmit(uint8_t *c);

void uart_write(uint8_t *c);
void uart_write_n(uint8_t *c, int n);

bool uart_rx_ready(void);
uint8_t uart_read(void);
void uart_read1(void);

#endif	/* XC_HEADER_TEMPLATE_H */