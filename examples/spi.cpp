#include "../bcm2835.h"
#include "../src/Spi.h"
#include <stdio.h>

int main() {
    Serial* spi = new Spi(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE0, BCM2835_SPI_CLOCK_DIVIDER_65536, 
                          BCM2835_SPI_CS0, LOW);
    uint8_t send_data = 0x23;
    uint8_t read_data = spi->transfer(send_data);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X. \n", send_data, read_data);
    if (send_data != read_data)
      printf("Do you have the loopback from MOSI to MISO connected?\n");
    delete spi;
    return 0;
}