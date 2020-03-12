#pragma once
#include "mbed.h"

namespace Mamary{
    class EEPROM{
        public:
            EEPROM(I2C &i2c_obj);       // Here you have to give a pointer for the I2C object that is used for interfacing with the eeprom
        private:
            const char addr = 0x50 << 1;    // The only avalible I2C Address for our eeprom
            char[] readData(char[] registerAddress, int size);
            void writeData(char[] registerAddress, char[] writeData);
            I2C &i2cbus;
    }
}