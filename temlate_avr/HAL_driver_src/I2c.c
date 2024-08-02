#include "C:\temlate_avr\main.h"
#include <util/twi.h>
/// @brief функция для инициализации I2c
/// @param i2c_init 
void HAL_Init_I2c(INIT_I2C *i2c_init)
{
TWSR = i2c_init->Divide;
TWBR = ((i2c_init->Frequency *10)-i2c_init->Frequency)/2;
TWCR = (1 << TWEN);
}

void i2c_start(void) {
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));  // ждем, пока стартовая передача не завершится
}

void i2c_stop(void) {
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
    while (TWCR & (1<<TWSTO));  // ждем, пока остановка будет завершена
}

void i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));  // ждем завершения передачи
}

uint8_t i2c_read_ack(void) {
    TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));  // ждем завершения получения данных
    return TWDR;
}

uint8_t i2c_read_nack(void) {
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));  // ждем завершения получения данных
    return TWDR;
}

/// @brief функция для отправки данных по I2c
/// @param device_addr адресс устройства
/// @param data отправляемые данные
void HAL_I2c_Transmit(uint8_t device_addr, uint8_t data) {
    i2c_start();
    i2c_write(device_addr << 1);  // отправляем адрес устройства с битом записи
    i2c_write(data);
    i2c_stop();
}

/// @brief функция для чтения данных по I2c 
/// @param device_addr адресс устрройства
/// @param data считываемые данные
uint8_t HAL_I2c_Recive(uint8_t device_addr, uint8_t *data) {
    i2c_start();
    i2c_write((device_addr << 1) | 1);  // отправляем адрес устройства с битом чтения
    *data = i2c_read_nack();
    i2c_stop();
    return *data;
}

uint8_t i2c_scan_start(uint8_t address) {
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));

    TWDR = address;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));

    return (TWSR & 0xF8) != TW_MT_SLA_ACK;
}

/// @brief функция для поиска адресса I2c устройства
/// @return возвращает адресс
uint8_t HAL_I2c_Scan()
{
    uint8_t address, nDevices;
            nDevices = 0;
        for (address = 1; address < 128; address++) {
            if (address == HAL_I2c_Recive(address, nDevices)) {
            }
            i2c_stop();
        }
        return(address);
    }
        