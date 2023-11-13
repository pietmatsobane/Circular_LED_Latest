/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GENERAL_FUNCTIONS_H
#define	GENERAL_FUNCTIONS_H

#include <xc.h> // include processor files - each processor file is guarded.  

void system_initialize(void);
void pin_init(void);
void enable_interrupts(void);
void disable_interrupts(void);
void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);


void pps_unlock(void);
void pps_lock(void);

uint8_t Dynamic_string[] = {};
uint8_t Startup_string[] = {"The program has started! \n"};
uint8_t test_string1[] = {"Successfully Done\n"};

uint8_t globalByte = 0;

#endif	/* XC_HEADER_TEMPLATE_H */

