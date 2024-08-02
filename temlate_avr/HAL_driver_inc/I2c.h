
#include <util/twi.h>

#define divide_by_1 0
#define divide_by_4 1
#define divide_by_16 2
#define divide_by_64 3

 #define _16mhz 16
 #define _8mhz 8
 #define _1mhz 1

 /// @brief структура для инициализации I2c 
 typedef struct
 {
uint8_t Divide; //предделитель 
uint8_t Frequency; // частота микроконтроллера
 }INIT_I2C;

 void HAL_Init_I2c(INIT_I2C *i2c_init);
uint8_t HAL_I2c_Recive(uint8_t device_addr, uint8_t *data);
void HAL_I2c_Transmit(uint8_t device_addr, uint8_t data);
uint8_t i2c_read_nack(void);
uint8_t i2c_read_ack(void);
void i2c_write(uint8_t data);
void i2c_stop(void);
void i2c_start(void);
uint8_t i2c_scan_start(uint8_t address);
uint8_t HAL_I2c_Scan();