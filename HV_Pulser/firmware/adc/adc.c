//!
//! \file       adc.c
//! \author     kg
//! \date       2024-04-05
//!
//! \brief      adc dac pio.
//!

//---------------------------------------------------------------------------
// INCLUDES
//---------------------------------------------------------------------------

#include "adc.h"


//---------------------------------------------------------------------------
// GLOBAL VARIABLES __asm volatile ("nop":);
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// GPIO delays
//---------------------------------------------------------------------------
void delay_140ns()
{
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
}
void delay_50ns()
{
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
}

//---------------------------------------------------------------------------
// PULSE GPIOS INIT FUNCTION
//---------------------------------------------------------------------------
void pulse_gpios_init()
{
    gpio_init(PULSPOS);
    gpio_init(PULSNEG);
    gpio_init(PULSDMP);
    gpio_init(PULSEOE);
    gpio_set_dir(PULSPOS, GPIO_OUT);
    gpio_set_dir(PULSNEG, GPIO_OUT);
    gpio_set_dir(PULSDMP, GPIO_OUT);
    gpio_set_dir(PULSEOE, GPIO_OUT);
    gpio_put(PULSPOS, 0); // P+
    gpio_put(PULSNEG, 0); // P- 
    gpio_put(PULSDMP, 0); // Pdamp
    gpio_put(PULSEOE, 1); // Activates OE for the pulser
}

//---------------------------------------------------------------------------
// GPIO PULSE SEQUENCE FUNCTION
//---------------------------------------------------------------------------
void pulse()
{



       	    // waits 50ns
            delay_50ns();
            // P-Positive for 140ns
            gpio_put(PULSPOS, 1);
            delay_140ns();
            gpio_put(PULSPOS, 0);
       	    // waits 50ns
            delay_50ns();
            // P-Negative for 140ns
            gpio_put(PULSNEG, 1);
            delay_140ns();
            gpio_put(PULSNEG, 0);
            // Waits a bit
            delay_140ns();
            // Damps signal
            gpio_put(PULSDMP, 1);
            sleep_us(7);
            gpio_put(PULSDMP, 0);
            sleep_us(150);


}

