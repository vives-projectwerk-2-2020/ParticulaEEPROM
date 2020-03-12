#include "mbed.h"
#include "EEPROM.h"


namespace Mamary{
    EEPROM::EEPROM(I2C &i2c_obj){
        i2cbus = &i2c_obj;
    }

    char[] EEPROM::readData(char[] registerAddress, int size){
        char dataRead[size];
        i2cbus.write(addr, registerAddress, 2, true);
        i2cbus.read(addr, dataRead, size);
        return dataRead;
    }

    void EEPROM::writeData(char[] registerAddress, char[] writeData){
        int arraySize = sizeof(writeData)/sizeof(writeData[0]);
        char dataWrite[arraySize+2];
        dataWrite[0] = registerAddress[0];
        dataWrite[1] = registerAddress[1];
        for( int i = 0; i< arraySize; i++){
            dataWrite[i+2] = writeData[i];
        }
        i2cbus.write(addr, dataWrite, arraySize+2);
    }
}