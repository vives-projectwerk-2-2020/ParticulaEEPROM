#include "mbed.h"
#include "EEPROM.h"

Serial pc(USBTX, USBRX);

int main(void) {
    pc.printf("\r\n\r\n[Particula] Loading Firmware ...");
    I2C i2cbus(D14,D15);
    Mamary::EEPROM eeprom(&i2cbus);
    char buffer[32] = {0};
    eeprom.read(buffer, 32, 0);
    printf("\r\nReading for eeprom #1\r\n");
    for(int i = 0; i<32; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    printf("Witing to eeprom\r\n");
    char data[4] = {0, 0, 0, 0};
    eeprom.write(data, 4, 6);

    eeprom.read(buffer, 32, 0);
    printf("Reading for eeprom #2\r\n");
    for(int i = 0; i<32; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    eeprom.read(buffer, 32, 0);
    printf("Reading for eeprom #3\r\n");
    for(int i = 0; i<32; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\r\n");

    while (true) {
        ThisThread::sleep_for(30000);
    }
    return 0;
}