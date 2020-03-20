#pragma once
#include "mbed.h"

namespace Mamary{
    class EEPROM{
        public:
            EEPROM(I2C * i2c_obj);       // Here you have to give a pointer for the I2C object that is used for interfacing with the eeprom
            char readData(char registerAddress, unsigned int size);
            void writeData(char registerAddress, char writeData);
        private:
            const char addr = 0x50 << 1;    // The only avalible I2C Address for our eeprom
            I2C &i2c_obj;
            I2C i2cbus;
    };
};