#include "Spi.h"
#include <math.h>
#include <iostream>

using namespace std;

Spi::Spi(uint8_t bit_order, uint8_t data_mode, uint16_t clock_divider, uint8_t chip_select, uint8_t active) {
    if (!bcm2835_init()) {
        cerr << "Failed to initialise BCM module";
        exit(EXIT_FAILURE);
    }
    if (!bcm2835_spi_begin()) {
        cerr << "Failed to start SPI";
        exit(EXIT_FAILURE);
    }
    validate_order(bit_order);
    validate_data_mode(data_mode);
    validate_clock_divider(clock_divider);
    validate_chip_select(chip_select);

    bcm2835_spi_setBitOrder(bit_order);      
    bcm2835_spi_setDataMode(data_mode);                   
    bcm2835_spi_setClockDivider(clock_divider); 
    bcm2835_spi_chipSelect(chip_select);                      
    bcm2835_spi_setChipSelectPolarity(chip_select, active); 
}

void Spi::validate_order(uint8_t bit_order) {
    if (bit_order != BCM2835_SPI_BIT_ORDER_LSBFIRST && bit_order != BCM2835_SPI_BIT_ORDER_MSBFIRST) {
        cerr << "Bit order must be LSB or MSB";
        exit(EXIT_FAILURE);
    }
}

void Spi::validate_data_mode(uint8_t data_mode) {
    if (data_mode != BCM2835_SPI_MODE0 && data_mode != BCM2835_SPI_MODE1 &&
        data_mode != BCM2835_SPI_MODE2 && data_mode != BCM2835_SPI_MODE3) {
            cerr << "Wrong data mode";
            exit(EXIT_FAILURE);
        }
}

void Spi::validate_clock_divider(uint16_t clock_divider) {
    if(clock_divider == 0) {
        return;
    }
    double result = log2((double)clock_divider);
    if (result > 15 || result < 0) {
        cerr << "Wrong clock divider";
        exit(EXIT_FAILURE);
    }
}

void Spi::validate_chip_select(uint8_t chip_select) {
    if (chip_select != BCM2835_SPI_CS0 && chip_select != BCM2835_SPI_CS1 &&
        chip_select != BCM2835_SPI_CS2 && chip_select != BCM2835_SPI_CS_NONE) {
            cerr << "Wrong chip select";
            exit(EXIT_FAILURE);
        }
}

Spi::~Spi() {
    bcm2835_close();
    bcm2835_spi_end();
}

uint8_t Spi::transfer(uint8_t data) {
    return bcm2835_spi_transfer(data);
}