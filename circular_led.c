/*
 * File:   circular-led.c
 * Author: Piet

 */


#include <xc.h>
#include "main_system_header.h"

void One_Led_Clockwise(void){
    /*****************Count and Speed Bytes******************/
    Count.ByteCount[0] = uart_read();   //LSB Byte
    Count.ByteCount[1] = uart_read();   //MSB Byte
    Speed.ByteSpeed[0] = uart_read();   //LSB Byte
    Speed.ByteSpeed[1] = uart_read();   //MSB Byte
    /********************************************************/
    sprintf(print_buffer, "%x ",Count.AnimCount);
    uart_write(print_buffer);
    sprintf(print_buffer, "%x ",Speed.AnimSpeed);
    uart_write(print_buffer);
    //uart_write(Animation1);
    for(uint16_t repeat = 0; repeat < Count.AnimCount; repeat++){
        DATA = HIGH;
        Shift_data();
        Display_data();
        DATA = LOW;
        for(LED = 0;LED<43;LED++){
            Shift_data();
            Display_data();
            for(uint16_t rate = 0; rate < Speed.AnimSpeed; rate++){   
                __delay_ms(1);
            }   
        }
        Clear_Data();
    }
    return;
}

void Draw_Circle(void){
    /*****************Count and Speed Bytes******************/
    Count.ByteCount[0] = uart_read();   //LSB Byte
    Count.ByteCount[1] = uart_read();   //MSB Byte
    Speed.ByteSpeed[0] = uart_read();   //LSB Byte
    Speed.ByteSpeed[1] = uart_read();   //MSB Byte
    /******************************************For Debugging*/
    //uart_write(Animation2);
    for(uint16_t repeat = 0; repeat < Count.AnimCount; repeat++){
        DATA = HIGH;
        for(LED = 0;LED<44;LED++){
            Shift_data();
            Display_data();
            for(uint16_t rate = 0; rate < Speed.AnimSpeed; rate++){
                __delay_ms(1);
            } 
        }
        Clear_Data();
    }
}

void Draw_Circle2(void){
    DATA = HIGH;
    for(LED = 0;LED<44;LED++){
        Shift_data();
        Display_data();
        __delay_ms(50);
    }
        LED = 0;
}

void Reverse_Circle(void){
    /*****************Count and Speed Bytes******************/
    Count.ByteCount[0] = uart_read();   //LSB Byte
    Count.ByteCount[1] = uart_read();   //MSB Byte
    Speed.ByteSpeed[0] = uart_read();   //LSB Byte
    Speed.ByteSpeed[1] = uart_read();   //MSB Byte
    for(uint16_t repeat = 0; repeat < Count.AnimCount; repeat++){
        Counter2 = 0;
        Counter3 = 0;
        Shift_counter1 = 1;
        Shift_counter2 = 43;
        Main_counter = 0;
        for(Main_counter=0;Main_counter<44;Main_counter++){
            for(Counter3=0;Counter3<Shift_counter1;Counter3++){
                DATA = HIGH;
                Shift_data();
            }
            for(Counter2=Shift_counter2;Counter2>1;Counter2--){
                DATA = LOW;
                Shift_data();
            }
        Shift_counter1++;
        Shift_counter2--;
        Display_data();
        //Clear_data();
        for(uint16_t rate = 0; rate < Speed.AnimSpeed; rate++){   
                __delay_ms(1);
            }
    }            
    }
    
}

void Inverse_One_Led(void){
    DATA = HIGH;
    for(Global_counter=0;Global_counter<43;Global_counter++){
        Shift_data();
    }
    Display_data();
    DATA = LOW;
    Shift_data();
    Shift_data();
    DATA = HIGH;
    for(Global_counter=0;Global_counter<42;Global_counter++){
        Shift_data();
        Display_data();
        __delay_ms(50);
    }
}

void Open_Book_Normal(void){
    Counter2 = 21;
    Counter3 = 1;
    Main_counter = 0;
    for(Global_counter=0;Global_counter<22;Global_counter++){
        DATA = HIGH;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        DATA = LOW;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        DATA = HIGH;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        Display_data();
        Counter2--;
        Counter3 = Counter3 + 2;
        __delay_ms(100);
    }
}

void Open_Book_Fast(void){
    Counter2 = 21;
    Counter3 = 1;
    Main_counter = 0;
    for(Global_counter=0;Global_counter<22;Global_counter++){
        DATA = LOW;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        DATA = HIGH;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        DATA = LOW;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        Display_data();
        Counter2--;
        Counter3 = Counter3 + 2;
        __delay_ms(50);
    }
    
}

void Close_book(void){
    Counter2 = 42;
    Counter3 = 1;
    Main_counter = 0;
    for(Global_counter=0;Global_counter<22;Global_counter++){
        DATA = HIGH;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        DATA = LOW;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        DATA = HIGH;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        Display_data();
        Counter2 = Counter2 - 2;
        Counter3++;
        __delay_ms(50);
    }
}

void Inverse_Open_Book(void){
    Counter2 = 21;
    Counter3 = 1;
    Main_counter = 0;
    for(Global_counter=0;Global_counter<22;Global_counter++){
        DATA = HIGH;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        DATA = LOW;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        DATA = HIGH;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        Display_data();
        Counter2--;
        Counter3 = Counter3 + 2;
        __delay_ms(50);
    }
    
}

void Inverse_Close_Book(void){
    Counter2 = 42;
    Counter3 = 1;
    Main_counter = 0;
    for(Global_counter=0;Global_counter<22;Global_counter++){
        DATA = LOW;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        DATA = HIGH;
        for(Main_counter=Counter2;Main_counter>0;Main_counter--){
            Shift_data();
        }
        DATA = LOW;
        for(Main_counter=0;Main_counter<Counter3;Main_counter++){
            Shift_data();
        }
        Display_data();
        Counter2 = Counter2 - 2;
        Counter3++;
        __delay_ms(50);
    }
}

void Alternate_Leds(uint8_t *LedCounter){
    DATA = HIGH;
    uint8_t ShiftCount = (43/(*LedCounter));

    for(LED = 0;LED<ShiftCount;LED++){
        for(uint8_t Count = *LedCounter; Count>0;Count--){
            Shift_data();
            Display_data();
        }
        DATA = ~DATA;
        __delay_ms(200);
    }
    LED = 0;
}

void Clockwise_Wheel(uint8_t *LedCounter){
    DATA = HIGH;
    uint8_t ShiftCount = (43/(*LedCounter));
    for(LED = 0;LED<ShiftCount;LED++){
        for(uint8_t Count = *LedCounter; Count>0;Count--){
            Shift_data();
            Display_data();
            __delay_ms(100);
        }
        DATA = LOW;
        for(uint8_t temp = 0; temp < (*LedCounter);temp++){
            Shift_data();
            Display_data();
            __delay_ms(100);
        }
        DATA = HIGH;
    }
    
        LED = 0;
}

void Graphic_Counter(uint8_t *c){
    uint8_t Main_Counter = 0;
    uint8_t Off_Leds = 0;
    uint8_t Seconds = 0;
    uint8_t temp = 1;
    
    for(Seconds= (45-(*c)); Seconds > 0; Seconds--){
        DATA = HIGH;
        for(Main_Counter = 0; Main_Counter < (*c); Main_Counter++){ 
            Shift_data(); 
        }
        DATA = LOW;
        for(Off_Leds = 0; Off_Leds <temp ; Off_Leds++){
            Shift_data();
        }
        temp = temp + 1;
        DATA = HIGH;
        for(uint8_t temp1 = Seconds; temp1 > 0; temp1--){
            Shift_data();
        }
        Display_data();
        __delay_ms(10);
        Clear_Data();
    }
    __delay_ms(100);
}

void Graphic_Counter1(uint8_t *c){
    uint8_t Main_Counter = 0;
    uint8_t Off_Leds = 0;
    uint8_t Seconds = 0;
    uint8_t temp = 0;
    
    for(Seconds= (45-(*c)); Seconds > 0; Seconds--){
        DATA = HIGH;
        for(Main_Counter = 0; Main_Counter < (*c); Main_Counter++){ 
            Shift_data(); 
        }
        DATA = LOW;
        for(Off_Leds = 0; Off_Leds <Seconds ; Off_Leds++){
            Shift_data();
        }
        temp = temp + 1;
        DATA = HIGH;
        for(uint8_t temp1 = temp; temp1 > 0; temp1--){
            Shift_data();
        }
        Display_data();
        __delay_ms(20);
        Clear_Data();
    }
    //__delay_ms(100);
}


/***************************************************************************/
void Clear_Data(void){
   // uart_write(Clear_Data_MSG);
    DATA = LOW;
    for(LED = 0;LED<43;LED++){
        Shift_data();
        //__delay_ms(10);
    }
    Display_data();
    LED = 0;
}
void Shift_data(void){
    S_CLOCK = LOW;
    S_CLOCK = HIGH;
    S_CLOCK = LOW;
}

void Display_data(void){
    D_CLOCK = LOW;
    D_CLOCK = HIGH;
    D_CLOCK = LOW;
}
