#include "mbed.h"
#include "EEPROM.h"


namespace Mamary{
    EEPROM::EEPROM(I2C * i2cBus){
        this->i2cBus = i2cBus;
    }

    void EEPROM::read(char buffer[], unsigned int length, unsigned int offset){
        i2cBus->write(i2cAddress, (char*)&offset , 2);
        i2cBus->read(i2cAddress, buffer, length);
    }

    void EEPROM::write(char buffer[], unsigned int length, unsigned int offset){
        char data[length+2];
        data[0] = (offset >> 8) & 0xFF;
        data[1] = offset & 0xFF;
        for(unsigned int i = 0; i<length; i++){
            data[i+2] = buffer[i];
        }
        i2cBus->write(i2cAddress, data, length+2);
        // i2cBus->write(i2cAddress, (char*)&offset , 2);
        // i2cBus->write(i2cAddress, buffer , length);
        // for(unsigned int i = 0; i < length; i++){
        //     char data[] = {
        //         (offset >> 8) & 0xFF,
        //         offset & 0xFF,
        //         buffer[i]
        //     };
        //     i2cBus->write(i2cAddress, data, sizeof(data));
        //     offset++;
        // }
    }
};