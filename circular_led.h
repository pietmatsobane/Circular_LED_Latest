
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CIRCULAR_LED_H
#define	CIRCULAR_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define DATA        LATAbits.LATA2
#define D_CLOCK     LATCbits.LATC0
#define S_CLOCK     LATAbits.LATA0
#define CLEAR       LATCbits.LATC2
#define OUTPUT_EN   LATCbits.LATC3
#define HIGH        1
#define LOW         0

#define ANIMATION_HEADER        0x65    //First Byte for every animation
#define ANIMATION_1             0x01    //One LED clockwise
#define ANIMATION_2             0x02    //Draw circle Clockwise
#define ANIMATION_3             0x03
#define ANIMATION_4             0x04
#define ANIMATION_5             0x05
#define ANIMATION_6             0x06
#define ANIMATION_7             0x07
#define ANIMATION_8             0x08
#define ANIMATION_9             0x09
#define ANIMATION_10            0x0A
#define ANIMATION_11            0x0B
#define ANIMATION_12            0x0C
#define ANIMATION_13            0x0D
#define ANIMATION_14            0x0E

void Shift_data(void);
void Display_data(void);    
void Clear_Data(void);             
void One_Led_Clockwise(void);   //Animation #1
void Draw_Circle();             //Animation #2
void Draw_Circle2(void);        //Animation #3
void Reverse_Circle(void);      //Animation #4
void Flash(void);               //Animation #5
void Inverse_One_Led(void);     //Animation #6
void Open_Book_Normal(void);    //Animation #7
void Inverse_Open_Book(void);   //Animation #8
void Open_Book_Fast(void);      //Animation #9
void Close_book(void);          //Animation #10
void Inverse_Close_Book(void);  //Animation #11
void Close_book2(void);         //Animation #10A
void Alternate_Leds(uint8_t *LedCounter);   //Animation #13 requires for loop
void Clockwise_Wheel(uint8_t *LedCounter);  //Animation #14 requires for loop
void Graphic_Counter(uint8_t *c);           //Animation #15 requires for loop
void Graphic_Counter1(uint8_t *c);          //Animation #15A requires for loop
void Led_Pendulum(uint8_t *c);              //Animation #17 requires for loop
void led_Swinging(void);

union AnimationCount{
    uint8_t ByteCount[2];
    uint16_t AnimCount;
};
union AnimationSpeed{
    uint8_t ByteSpeed[2];
    uint16_t AnimSpeed;
};

uint8_t HeaderByte;
uint8_t AnimationByte;
uint8_t EndByte;

union AnimationCount Count;
union AnimationSpeed Speed;

uint24_t LED = 0;
uint24_t Counter2 = 0;
uint24_t Counter3 = 0;
uint24_t Shift_counter1 = 0;
uint24_t Shift_counter2 = 0;
uint24_t Main_counter = 0;
uint24_t Global_counter =0;

uint8_t LedCount = 0;

uint8_t Animation1[]    = "Animation 1: One LED Clockwise\n";
uint8_t Animation2[]    = "Animation 2: Draw Circle\n";
uint8_t Reverse_Circle1[]   = "\nDraw a circle Clockwise   20ms";
uint8_t Clear_Data_MSG[]    = "\nClearing all registers    20ms";
uint8_t print_buffer[100] = {0};
#endif	/* XC_HEADER_TEMPLATE_H */

