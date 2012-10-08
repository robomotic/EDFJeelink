#ifndef SPI_H_
#define SPI_H_

#include <stdio.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06
//#define SPI_CLOCK_DIV64 0x07

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

// Pins
#define RFM_IRQ      2 // PD2
#define SS_DDR      DDRB
#define SS_PORT     PORTB
#define SS_BIT       2 // for PORTB: 2 = d.10, 1 = d.9, 0 = d.8

//#define SPI_SS      10 // PB2, pin 16 (confirmed from Nanode RF schematic)
//#define SPI_MOSI    11 // PB3, pin 17
//#define SPI_MISO    12 // PB4, pin 18
//#define SPI_SCK     13 // PB5, pin 19

namespace spi {
	/* Select or de-select the RFM.
	 *
	 * @param state: if true then select the RFM
	 *               (ready for data transfer)
	 */
	void select(const bool state);

	/**
	 * Initialise the ATmega's SPI hardware for use with the RFM.
	 */
	void init();

	/**
	 * Send a byte over the SPI bus.
	 *
	 * @return 8-bit response
	 */
	const uint8_t transfer_byte(const uint8_t& out);

	/**
	 * Send a 16-bit word over the SPI bus, with MSB first.
	 *
	 * @return 16-bit response. First response is MSB.
	 */
	const uint16_t transfer_word(const uint16_t& cmd, const bool& ss = true);
};

#endif /* SPI_H_ */
