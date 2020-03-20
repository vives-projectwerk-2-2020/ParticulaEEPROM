#include "mbed.h"
#include "EEPROM.h"

Serial pc(USBTX, USBRX);

int main(void) {
    pc.printf("\r\n\r\n[Particula] Loading Firmware ...");
    I2C i2cbus(D14,D15);
    Mamary::EEPROM eeprom(&i2cbus);
    char buffer[32] = {0};
    eeprom.read(buffer, 32, 0);
    printf("Reading for eeprom\n");
    for(int i = 0; i<32; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\n");

    printf("witing to eeprom\n");
    char data[4] = {1, 2, 3, 4};
    eeprom.write(buffer, 4, 2);

    eeprom.read(buffer, 32, 0);
    printf("Reading for eeprom\n");
    for(int i = 0; i<32; i++){
        printf("0x%x ", buffer[i]);
    }
    printf("\n");

    while (true) {
        ThisThread::sleep_for(30000);
    }
    return 0;
}