// Map of Arduino pins to avr bit, ddr, port, pin
// Credit Paul Stoffregen for idea
#ifndef ArduinoPins_h
#define ArduinoPins_h

#define PIN_BITNUM(pin) (PIN ## pin ## _BITNUM)
#define PIN_PORTREG(pin) (PIN ## pin ## _PORTREG)
#define PIN_DDRREG(pin) (PIN ## pin ## _DDRREG)
#define PIN_PINREG(pin) (PIN ## pin ## _PINREG)
#ifndef _BV
#define _BV(n) (1<<(n))
#endif

#if defined(__AVR_ATmega1280__)
// Mega Arduino

// Two Wire (aka I2C) ports
#define SDA_PIN 20
#define SCL_PIN 21

// SPI port
#define SS_PIN 53
#define MOSI_PIN 51
#define MISO_PIN 50
#define SCK_PIN 52

// bit number for all digital pins
#define PIN0_BITNUM 0
#define PIN1_BITNUM 1
#define PIN2_BITNUM 4
#define PIN3_BITNUM 5
#define PIN4_BITNUM 5
#define PIN5_BITNUM 3
#define PIN6_BITNUM 3
#define PIN7_BITNUM 4
#define PIN8_BITNUM 5
#define PIN9_BITNUM 6
#define PIN10_BITNUM 4
#define PIN11_BITNUM 5
#define PIN12_BITNUM 6
#define PIN13_BITNUM 7
#define PIN14_BITNUM 1
#define PIN15_BITNUM 0
#define PIN16_BITNUM 1
#define PIN17_BITNUM 0
#define PIN18_BITNUM 3
#define PIN19_BITNUM 2
#define PIN20_BITNUM 1
#define PIN21_BITNUM 0
#define PIN22_BITNUM 0
#define PIN23_BITNUM 1
#define PIN24_BITNUM 2
#define PIN25_BITNUM 3
#define PIN26_BITNUM 4
#define PIN27_BITNUM 5
#define PIN28_BITNUM 6
#define PIN29_BITNUM 7
#define PIN30_BITNUM 7
#define PIN31_BITNUM 6
#define PIN32_BITNUM 5
#define PIN33_BITNUM 4
#define PIN34_BITNUM 3
#define PIN35_BITNUM 2
#define PIN36_BITNUM 1
#define PIN37_BITNUM 0
#define PIN38_BITNUM 7
#define PIN39_BITNUM 2
#define PIN40_BITNUM 1
#define PIN41_BITNUM 0
#define PIN42_BITNUM 7
#define PIN43_BITNUM 6
#define PIN44_BITNUM 5
#define PIN45_BITNUM 4
#define PIN46_BITNUM 3
#define PIN47_BITNUM 2
#define PIN48_BITNUM 1
#define PIN49_BITNUM 0
#define PIN50_BITNUM 3
#define PIN51_BITNUM 2
#define PIN52_BITNUM 1
#define PIN53_BITNUM 0
#define PIN54_BITNUM 0
#define PIN55_BITNUM 1
#define PIN56_BITNUM 2
#define PIN57_BITNUM 3
#define PIN58_BITNUM 4
#define PIN59_BITNUM 5
#define PIN60_BITNUM 6
#define PIN61_BITNUM 7
#define PIN62_BITNUM 0
#define PIN63_BITNUM 1
#define PIN64_BITNUM 2
#define PIN65_BITNUM 3
#define PIN66_BITNUM 4
#define PIN67_BITNUM 5
#define PIN68_BITNUM 6
#define PIN69_BITNUM 7

// output register for digital pins
#define PIN0_PORTREG PORTE
#define PIN1_PORTREG PORTE
#define PIN2_PORTREG PORTE
#define PIN3_PORTREG PORTE
#define PIN4_PORTREG PORTG
#define PIN5_PORTREG PORTE
#define PIN6_PORTREG PORTH
#define PIN7_PORTREG PORTH
#define PIN8_PORTREG PORTH
#define PIN9_PORTREG PORTH
#define PIN10_PORTREG PORTB
#define PIN11_PORTREG PORTB
#define PIN12_PORTREG PORTB
#define PIN13_PORTREG PORTB
#define PIN14_PORTREG PORTJ
#define PIN15_PORTREG PORTJ
#define PIN16_PORTREG PORTH
#define PIN17_PORTREG PORTH
#define PIN18_PORTREG PORTD
#define PIN19_PORTREG PORTD
#define PIN20_PORTREG PORTD
#define PIN21_PORTREG PORTD
#define PIN22_PORTREG PORTA
#define PIN23_PORTREG PORTA
#define PIN24_PORTREG PORTA
#define PIN25_PORTREG PORTA
#define PIN26_PORTREG PORTA
#define PIN27_PORTREG PORTA
#define PIN28_PORTREG PORTA
#define PIN29_PORTREG PORTA
#define PIN30_PORTREG PORTC
#define PIN31_PORTREG PORTC
#define PIN32_PORTREG PORTC
#define PIN33_PORTREG PORTC
#define PIN34_PORTREG PORTC
#define PIN35_PORTREG PORTC
#define PIN36_PORTREG PORTC
#define PIN37_PORTREG PORTC
#define PIN38_PORTREG PORTD
#define PIN39_PORTREG PORTG
#define PIN40_PORTREG PORTG
#define PIN41_PORTREG PORTG
#define PIN42_PORTREG PORTL
#define PIN43_PORTREG PORTL
#define PIN44_PORTREG PORTL
#define PIN45_PORTREG PORTL
#define PIN46_PORTREG PORTL
#define PIN47_PORTREG PORTL
#define PIN48_PORTREG PORTL
#define PIN49_PORTREG PORTL
#define PIN50_PORTREG PORTB
#define PIN51_PORTREG PORTB
#define PIN52_PORTREG PORTB
#define PIN53_PORTREG PORTB
#define PIN54_PORTREG PORTF
#define PIN55_PORTREG PORTF
#define PIN56_PORTREG PORTF
#define PIN57_PORTREG PORTF
#define PIN58_PORTREG PORTF
#define PIN59_PORTREG PORTF
#define PIN60_PORTREG PORTF
#define PIN61_PORTREG PORTF
#define PIN62_PORTREG PORTK
#define PIN63_PORTREG PORTK
#define PIN64_PORTREG PORTK
#define PIN65_PORTREG PORTK
#define PIN66_PORTREG PORTK
#define PIN67_PORTREG PORTK
#define PIN68_PORTREG PORTK
#define PIN69_PORTREG PORTK

// direction control register for digital pins
#define PIN0_DDRREG DDRE
#define PIN1_DDRREG DDRE
#define PIN2_DDRREG DDRE
#define PIN3_DDRREG DDRE
#define PIN4_DDRREG DDRG
#define PIN5_DDRREG DDRE
#define PIN6_DDRREG DDRH
#define PIN7_DDRREG DDRH
#define PIN8_DDRREG DDRH
#define PIN9_DDRREG DDRH
#define PIN10_DDRREG DDRB
#define PIN11_DDRREG DDRB
#define PIN12_DDRREG DDRB
#define PIN13_DDRREG DDRB
#define PIN14_DDRREG DDRJ
#define PIN15_DDRREG DDRJ
#define PIN16_DDRREG DDRH
#define PIN17_DDRREG DDRH
#define PIN18_DDRREG DDRD
#define PIN19_DDRREG DDRD
#define PIN20_DDRREG DDRD
#define PIN21_DDRREG DDRD
#define PIN22_DDRREG DDRA
#define PIN23_DDRREG DDRA
#define PIN24_DDRREG DDRA
#define PIN25_DDRREG DDRA
#define PIN26_DDRREG DDRA
#define PIN27_DDRREG DDRA
#define PIN28_DDRREG DDRA
#define PIN29_DDRREG DDRA
#define PIN30_DDRREG DDRC
#define PIN31_DDRREG DDRC
#define PIN32_DDRREG DDRC
#define PIN33_DDRREG DDRC
#define PIN34_DDRREG DDRC
#define PIN35_DDRREG DDRC
#define PIN36_DDRREG DDRC
#define PIN37_DDRREG DDRC
#define PIN38_DDRREG DDRD
#define PIN39_DDRREG DDRG
#define PIN40_DDRREG DDRG
#define PIN41_DDRREG DDRG
#define PIN42_DDRREG DDRL
#define PIN43_DDRREG DDRL
#define PIN44_DDRREG DDRL
#define PIN45_DDRREG DDRL
#define PIN46_DDRREG DDRL
#define PIN47_DDRREG DDRL
#define PIN48_DDRREG DDRL
#define PIN49_DDRREG DDRL
#define PIN50_DDRREG DDRB
#define PIN51_DDRREG DDRB
#define PIN52_DDRREG DDRB
#define PIN53_DDRREG DDRB
#define PIN54_DDRREG DDRF
#define PIN55_DDRREG DDRF
#define PIN56_DDRREG DDRF
#define PIN57_DDRREG DDRF
#define PIN58_DDRREG DDRF
#define PIN59_DDRREG DDRF
#define PIN60_DDRREG DDRF
#define PIN61_DDRREG DDRF
#define PIN62_DDRREG DDRK
#define PIN63_DDRREG DDRK
#define PIN64_DDRREG DDRK
#define PIN65_DDRREG DDRK
#define PIN66_DDRREG DDRK
#define PIN67_DDRREG DDRK
#define PIN68_DDRREG DDRK
#define PIN69_DDRREG DDRK

// input register for digital pins
#define PIN0_PINREG PINE
#define PIN1_PINREG PINE
#define PIN2_PINREG PINE
#define PIN3_PINREG PINE
#define PIN4_PINREG PING
#define PIN5_PINREG PINE
#define PIN6_PINREG PINH
#define PIN7_PINREG PINH
#define PIN8_PINREG PINH
#define PIN9_PINREG PINH
#define PIN10_PINREG PINB
#define PIN11_PINREG PINB
#define PIN12_PINREG PINB
#define PIN13_PINREG PINB
#define PIN14_PINREG PINJ
#define PIN15_PINREG PINJ
#define PIN16_PINREG PINH
#define PIN17_PINREG PINH
#define PIN18_PINREG PIND
#define PIN19_PINREG PIND
#define PIN20_PINREG PIND
#define PIN21_PINREG PIND
#define PIN22_PINREG PINA
#define PIN23_PINREG PINA
#define PIN24_PINREG PINA
#define PIN25_PINREG PINA
#define PIN26_PINREG PINA
#define PIN27_PINREG PINA
#define PIN28_PINREG PINA
#define PIN29_PINREG PINA
#define PIN30_PINREG PINC
#define PIN31_PINREG PINC
#define PIN32_PINREG PINC
#define PIN33_PINREG PINC
#define PIN34_PINREG PINC
#define PIN35_PINREG PINC
#define PIN36_PINREG PINC
#define PIN37_PINREG PINC
#define PIN38_PINREG PIND
#define PIN39_PINREG PING
#define PIN40_PINREG PING
#define PIN41_PINREG PING
#define PIN42_PINREG PINL
#define PIN43_PINREG PINL
#define PIN44_PINREG PINL
#define PIN45_PINREG PINL
#define PIN46_PINREG PINL
#define PIN47_PINREG PINL
#define PIN48_PINREG PINL
#define PIN49_PINREG PINL
#define PIN50_PINREG PINB
#define PIN51_PINREG PINB
#define PIN52_PINREG PINB
#define PIN53_PINREG PINB
#define PIN54_PINREG PINF
#define PIN55_PINREG PINF
#define PIN56_PINREG PINF
#define PIN57_PINREG PINF
#define PIN58_PINREG PINF
#define PIN59_PINREG PINF
#define PIN60_PINREG PINF
#define PIN61_PINREG PINF
#define PIN62_PINREG PINK
#define PIN63_PINREG PINK
#define PIN64_PINREG PINK
#define PIN65_PINREG PINK
#define PIN66_PINREG PINK
#define PIN67_PINREG PINK
#define PIN68_PINREG PINK
#define PIN69_PINREG PINK

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644__)
// ATMEL ATMEGA644P / SANGUINO
//
//                   +---\/---+
//  INT0 (D 0) PB0  1|        |40  PA0 (AI 0 / D31)
//  INT1 (D 1) PB1  2|        |39  PA1 (AI 1 / D30)
//  INT2 (D 2) PB2  3|        |38  PA2 (AI 2 / D29)
//   PWM (D 3) PB3  4|        |37  PA3 (AI 3 / D28)
//   PWM (D 4) PB4  5|        |36  PA4 (AI 4 / D27)
//  MOSI (D 5) PB5  6|        |35  PA5 (AI 5 / D26)
//  MISO (D 6) PB6  7|        |34  PA6 (AI 6 / D25)
//   SCK (D 7) PB7  8|        |33  PA7 (AI 7 / D24)
//             RST  9|        |32  AREF
//             VCC 10|        |31  GND
//             GND 11|        |30  AVCC
//           XTAL2 12|        |29  PC7 (D 23)
//           XTAL1 13|        |28  PC6 (D 22)
//  RX0 (D 8)  PD0 14|        |27  PC5 (D 21) TDI
//  TX0 (D 9)  PD1 15|        |26  PC4 (D 20) TDO
//  RX1 (D 10) PD2 16|        |25  PC3 (D 19) TMS
//  TX1 (D 11) PD3 17|        |24  PC2 (D 18) TCK
//  PWM (D 12) PD4 18|        |23  PC1 (D 17) SDA
//  PWM (D 13) PD5 19|        |22  PC0 (D 16) SCL
//  PWM (D 14) PD6 20|        |21  PD7 (D 15) PWM
//                   +--------+
//

#error Sanguino not tested

// Two Wire (aka I2C) ports
#define SDA_PIN 17
#define SCL_PIN 18

// SPI port
#define SS_PIN   4
#define MOSI_PIN 5
#define MISO_PIN 6
#define SCK_PIN  7

// bit number for all digital pins
#define PIN0_BITNUM 0
#define PIN1_BITNUM 1
#define PIN2_BITNUM 2
#define PIN3_BITNUM 3
#define PIN4_BITNUM 4
#define PIN5_BITNUM 5
#define PIN6_BITNUM 6
#define PIN7_BITNUM 7
#define PIN8_BITNUM 0
#define PIN9_BITNUM 1
#define PIN10_BITNUM 2
#define PIN11_BITNUM 3
#define PIN12_BITNUM 4
#define PIN13_BITNUM 5
#define PIN14_BITNUM 6
#define PIN15_BITNUM 7
#define PIN16_BITNUM 0
#define PIN17_BITNUM 1
#define PIN18_BITNUM 2
#define PIN19_BITNUM 3
#define PIN20_BITNUM 4
#define PIN21_BITNUM 5
#define PIN22_BITNUM 6
#define PIN23_BITNUM 7
#define PIN24_BITNUM 7
#define PIN25_BITNUM 6
#define PIN26_BITNUM 5
#define PIN27_BITNUM 4
#define PIN28_BITNUM 3
#define PIN29_BITNUM 2
#define PIN30_BITNUM 1
#define PIN31_BITNUM0

// output register for digital pins
#define PIN0_PORTREG PORTB
#define PIN1_PORTREG PORTB
#define PIN2_PORTREG PORTB
#define PIN3_PORTREG PORTB
#define PIN4_PORTREG PORTB
#define PIN5_PORTREG PORTB
#define PIN6_PORTREG PORTB
#define PIN7_PORTREG PORTB
#define PIN8_PORTREG PORTD
#define PIN9_PORTREG PORTD
#define PIN10_PORTREG PORTD
#define PIN11_PORTREG PORTD
#define PIN12_PORTREG PORTD
#define PIN13_PORTREG PORTD
#define PIN14_PORTREG PORTD
#define PIN15_PORTREG PORTD
#define PIN16_PORTREG PORTC
#define PIN17_PORTREG PORTC
#define PIN18_PORTREG PORTC
#define PIN19_PORTREG PORTC
#define PIN20_PORTREG PORTC
#define PIN21_PORTREG PORTC
#define PIN22_PORTREG PORTC
#define PIN23_PORTREG PORTC
#define PIN24_PORTREG PORTA
#define PIN25_PORTREG PORTA
#define PIN26_PORTREG PORTA
#define PIN27_PORTREG PORTA
#define PIN28_PORTREG PORTA
#define PIN29_PORTREG PORTA
#define PIN30_PORTREG PORTA
#define PIN31_PORTREG PORTA


// direction control register for digital pins
#define PIN0_DDRREG DDRB
#define PIN1_DDRREG DDRB
#define PIN2_DDRREG DDRB
#define PIN3_DDRREG DDRB
#define PIN4_DDRREG DDRB
#define PIN5_DDRREG DDRB
#define PIN6_DDRREG DDRB
#define PIN7_DDRREG DDRB
#define PIN8_DDRREG DDRD
#define PIN9_DDRREG DDRD
#define PIN10_DDRREG DDRD
#define PIN11_DDRREG DDRD
#define PIN12_DDRREG DDRD
#define PIN13_DDRREG DDRD
#define PIN14_DDRREG DDRD
#define PIN15_DDRREG DDRD
#define PIN16_DDRREG DDRC
#define PIN17_DDRREG DDRC
#define PIN18_DDRREG DDRC
#define PIN19_DDRREG DDRC
#define PIN20_DDRREG DDRC
#define PIN21_DDRREG DDRC
#define PIN22_DDRREG DDRC
#define PIN23_DDRREG DDRC
#define PIN24_DDRREG DDRA
#define PIN25_DDRREG DDRA
#define PIN26_DDRREG DDRA
#define PIN27_DDRREG DDRA
#define PIN28_DDRREG DDRA
#define PIN29_DDRREG DDRA
#define PIN30_DDRREG DDRA
#define PIN31_DDRREG DDRA


// input register for digital pins
#define PIN0_PINREG PINB
#define PIN1_PINREG PINB
#define PIN2_PINREG PINB
#define PIN3_PINREG PINB
#define PIN4_PINREG PINB
#define PIN5_PINREG PINB
#define PIN6_PINREG PINB
#define PIN7_PINREG PINB
#define PIN8_PINREG PIND
#define PIN9_PINREG PIND
#define PIN10_PINREG PIND
#define PIN11_PINREG PIND
#define PIN12_PINREG PIND
#define PIN13_PINREG PIND
#define PIN14_PINREG PIND
#define PIN15_PINREG PIND
#define PIN16_PINREG PINC
#define PIN17_PINREG PINC
#define PIN18_PINREG PINC
#define PIN19_PINREG PINC
#define PIN20_PINREG PINC
#define PIN21_PINREG PINC
#define PIN22_PINREG PINC
#define PIN23_PINREG PINC
#define PIN24_PINREG PINA
#define PIN25_PINREG PINA
#define PIN26_PINREG PINA
#define PIN27_PINREG PINA
#define PIN28_PINREG PINA
#define PIN29_PINREG PINA
#define PIN30_PINREG PINA
#define PIN31_PINREG PINA


#else // defined(__AVR_ATmega1280__)
// 168 and 328 Arduinos
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5 D 19) SCL
//      (D 0) PD0  2|    |27  PC4 (AI 4 D 18) SDA
//      (D 1) PD1  3|    |26  PC3 (AI 3 D 17)
//      (D 2) PD2  4|    |25  PC2 (AI 2 D 16)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1 D 15)
//      (D 4) PD4  6|    |23  PC0 (AI 0 D 14)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13) SCK
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12) MISO
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) MOSI PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) SS PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
//
// Two Wire (aka I2C) ports
#define SDA_PIN 18
#define SCL_PIN 19

// SPI port
//#define SS_PIN 10
#define SS_PIN 8
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13

// bit number for digital pins
#define PIN0_BITNUM 0
#define PIN1_BITNUM 1
#define PIN2_BITNUM 2
#define PIN3_BITNUM 3
#define PIN4_BITNUM 4
#define PIN5_BITNUM 5
#define PIN6_BITNUM 6
#define PIN7_BITNUM 7
#define PIN8_BITNUM 0
#define PIN9_BITNUM 1
#define PIN10_BITNUM 2
#define PIN11_BITNUM 3
#define PIN12_BITNUM 4
#define PIN13_BITNUM 5
#define PIN14_BITNUM 0
#define PIN15_BITNUM 1
#define PIN16_BITNUM 2
#define PIN17_BITNUM 3
#define PIN18_BITNUM 4
#define PIN19_BITNUM 5

// output register for all pins
#define PIN0_PORTREG PORTD
#define PIN1_PORTREG PORTD
#define PIN2_PORTREG PORTD
#define PIN3_PORTREG PORTD
#define PIN4_PORTREG PORTD
#define PIN5_PORTREG PORTD
#define PIN6_PORTREG PORTD
#define PIN7_PORTREG PORTD
#define PIN8_PORTREG PORTB
#define PIN9_PORTREG PORTB
#define PIN10_PORTREG PORTB
#define PIN11_PORTREG PORTB
#define PIN12_PORTREG PORTB
#define PIN13_PORTREG PORTB
#define PIN14_PORTREG PORTC
#define PIN15_PORTREG PORTC
#define PIN16_PORTREG PORTC
#define PIN17_PORTREG PORTC
#define PIN18_PORTREG PORTC
#define PIN19_PORTREG PORTC

// direction control register for digital pins
#define PIN0_DDRREG DDRD
#define PIN1_DDRREG DDRD
#define PIN2_DDRREG DDRD
#define PIN3_DDRREG DDRD
#define PIN4_DDRREG DDRD
#define PIN5_DDRREG DDRD
#define PIN6_DDRREG DDRD
#define PIN7_DDRREG DDRD
#define PIN8_DDRREG DDRB
#define PIN9_DDRREG DDRB
#define PIN10_DDRREG DDRB
#define PIN11_DDRREG DDRB
#define PIN12_DDRREG DDRB
#define PIN13_DDRREG DDRB
#define PIN14_DDRREG DDRC
#define PIN15_DDRREG DDRC
#define PIN16_DDRREG DDRC
#define PIN17_DDRREG DDRC
#define PIN18_DDRREG DDRC
#define PIN19_DDRREG DDRC

// input register for digital pins
#define PIN0_PINREG PIND
#define PIN1_PINREG PIND
#define PIN2_PINREG PIND
#define PIN3_PINREG PIND
#define PIN4_PINREG PIND
#define PIN5_PINREG PIND
#define PIN6_PINREG PIND
#define PIN7_PINREG PIND
#define PIN8_PINREG PINB
#define PIN9_PINREG PINB
#define PIN10_PINREG PINB
#define PIN11_PINREG PINB
#define PIN12_PINREG PINB
#define PIN13_PINREG PINB
#define PIN14_PINREG PINC
#define PIN15_PINREG PINC
#define PIN16_PINREG PINC
#define PIN17_PINREG PINC
#define PIN18_PINREG PINC
#define PIN19_PINREG PINC
#endif // defined(__AVR_ATmega1280__)
#endif // ArduinoPins_h