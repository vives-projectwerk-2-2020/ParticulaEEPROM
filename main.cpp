#include "mbed.h"
#include "EEPROM.h"

Serial pc(USBTX, USBRX);

int main(void) {
    unsigned int lengthtest = 40;
    pc.printf("\r\n\r\n[Particula] Loading Firmware ...");
    I2C i2cbus(D14,D15);
    Mamary::EEPROM eeprom(&i2cbus);
    char buffer[lengthtest] = {0};
    eeprom.read(buffer, lengthtest, 0);
    printf("\r\nReading for eeprom #1\r\n");
    for(int i = 0; i<lengthtest; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    printf("Witing to eeprom\r\n");
    char data[lengthtest];
    for(unsigned int i=0; i<lengthtest; i++){
        data[i] = 0x0;
    }
    eeprom.write(data, lengthtest, 15);

    eeprom.read(buffer, lengthtest, 0);
    printf("Reading for eeprom #2\r\n");
    for(int i = 0; i<lengthtest; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    eeprom.read(buffer, lengthtest, 0);
    printf("Reading for eeprom #3\r\n");
    for(int i = 0; i<lengthtest; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    while (true) {
        ThisThread::sleep_for(30000);
    }
    return 0;
}