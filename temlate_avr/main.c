#include "main.h"
UartInit uart;
INIT_I2C i2c;
GPIO_Init init;
void Inits_ports();

int main()
{
    uart.BoudRate = boud_9600;
    uart.ModeUart = TX;
    uart.WordLength =  MODE_8BIT;
    HAL_UartInit(&uart);

    i2c.Divide = divide_by_1;
    i2c.Frequency = _8mhz;
    HAL_Init_I2c(&i2c);
    init.Mode = OUTPUT;
    init.num_pin = GPIO_PIN_5;
    init.Port = GPIO_PORTB;
    init.Reg = GPIOB;
   // Inits_ports();
    HAL_InitPin(&init);
    Timer0_Init();
    unsigned long timer = 0;
    while(1)
    {
        if(HAL_GetTick()-timer>500)
        {
            HAL_GPIO_Togglepin(GPIO_PORTB, GPIO_PIN_5);
            timer = HAL_GetTick();
        }
            
            //_delay_ms(300);
    }
}


void Inits_ports()
{


    init.Mode = OUTPUT;
    init.num_pin = GPIO_PIN_1;
    init.Port = GPIO_PORTB;
    init.Reg = GPIOB;

    init.Mode = OUTPUT;
    init.num_pin = GPIO_PIN_2;
    init.Port = GPIO_PORTB;
    init.Reg = GPIOB;

    init.Mode = OUTPUT;
    init.num_pin = GPIO_PIN_3;
    init.Port = GPIO_PORTB;
    init.Reg = GPIOB;

    init.Mode = INPUT_PULLUP;
    init.num_pin = GPIO_PIN_4;
    init.Port = GPIO_PORTD;
    init.Reg = GPIOD;

    init.Mode = INPUT_PULLUP;
    init.num_pin = GPIO_PIN_7;
    init.Port = GPIO_PORTD;
    init.Reg = GPIOD;

    init.Mode = INPUT_PULLUP;
    init.num_pin = GPIO_PIN_6;
    init.Port = GPIO_PORTD;
    init.Reg = GPIOD;

    init.Mode = INPUT_PULLUP;
    init.num_pin = GPIO_PIN_5;
    init.Port = GPIO_PORTD;
    init.Reg = GPIOD;
}