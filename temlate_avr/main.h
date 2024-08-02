#include <avr/io.h>
#include <util/delay.h>
#include "HAL_driver_inc/GPIO.h"
#include "HAL_driver_inc/ADC.h"
#include "HAL_driver_inc/UART.h"
#include "HAL_driver_inc/I2c.h"
void Timer0_Init(void);
uint32_t HAL_GetTick();
ISR(TIMER0_COMPA_vect);