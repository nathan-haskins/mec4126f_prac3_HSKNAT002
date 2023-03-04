// Description----------------------------------------------------------------|
/*
 *
 */
// DEFINES AND INCLUDES-------------------------------------------------------|

#define STM32F051												   //COMPULSORY
#include "stm32f0xx.h"											   //COMPULSORY
#include "lcd_stm32f0.h"
#include <stdio.h> // For sprintf function (3.2)

// GLOBAL VARIABLES ----------------------------------------------------------|
struct age_data {
    uint8_t date;
    uint8_t month;
    uint16_t year; // not using uint8_t here because that would limit the years to 0-255
    uint8_t age;
} my_age;


// FUNCTION DECLARATIONS -----------------------------------------------------|

void main(void);                                                   //COMPULSORY

// MAIN FUNCTION -------------------------------------------------------------|

void main(void)
{
	my_age = (struct age_data){28, 3, 2001, 21};
	init_LCD(); // INITIALISE LCD

	int count = 0; // Counter variable for LCD display

	while(1)
	{
        char age_string[3]; // Convert age to a string [array - one for each digit in the age, and one for the null terminator character ('\0') to mark the end of the string.]
        sprintf(age_string, "%d", count);
        lcd_putstring(age_string);
        delay(120000);
        count++;
    	lcd_command(CLEAR);
        if(count  > my_age.age){count = 0;}
	}
}


// OTHER FUNCTIONS -----------------------------------------------------------|
