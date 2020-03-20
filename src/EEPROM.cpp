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
        if(length<=32) this->writePage(buffer, length, offset);
        else{
            char buffer32[] = {0};
            unsigned int length2 = 32;
            for(unsigned int i = 0; i < (int)(length/32); i++){
                for(unsigned int j = 0; j<32; j++){
                    buffer32[j] = buffer[(i*32)+j];
                }
                if(i<((int)(length/32)-1)) length2 = length%32;
                this->writePage(buffer32,length2,(offset+32*i));
            }
        }
        wait_ms(10); //write cycle delay
    }

    void EEPROM::writePage(char buffer[], unsigned int length, unsigned int offset){
        char data[length+2];
        data[0] = (offset >> 8) & 0xFF;
        data[1] = offset & 0xFF;
        for(unsigned int i = 0; i<length; i++){
            data[i+2] = buffer[i];
        }
        i2cBus->write(i2cAddress, data, length+2);
    }
};