#include "type.h"

void i2c_eeprom_write(u8 slaveAddr,

	                    u8 wBuffAddr,

                      u8 dat);

u8 i2c_eeprom_read(u8 slaveAddr,

                   u8 rBuffAddr);

void i2c_eeprom_page_write(u8 slaveAddr,

	                         u8 wBuffStartAddr,

                           u8 *p,

                           u8 nBytes);

void i2c_eeprom_page_read(u8 slaveAddr,

	                       u8 rBuffStartAddr,

                         u8 *p,

                         u8 nBytes);

