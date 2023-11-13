#ifndef MAIN_SYSTEM_HEADER_H
#define	MAIN_SYSTEM_HEADER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "conbits.h"
#include "general_functions.h"
#include "pin_manager.h"
#include "uart.h"
#include "circular_led.h"

void system_initialize(void);

#endif	/* XC_HEADER_TEMPLATE_H */