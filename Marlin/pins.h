#ifndef PINS_H
#define PINS_H

/****************************************************************************************
* OpenSL pin assingments (ATMEGA90USB1286)
* Requires the Teensyduino software with Teensy2.0++ selected in arduino IDE!
* See http://pryntech.com/wiki for more info
****************************************************************************************/
#if MOTHERBOARD == 81
#define MOTHERBOARD 81
#define KNOWN_BOARD 1

//Open SL Pins
#define GALVO_SS_PIN 20
#define LASER_PIN    24
#define R_LED 18
#define G_LED 19
#define B_LED 20

#define X_STEP_PIN         -1
#define X_DIR_PIN          -1
#define X_ENABLE_PIN       -1
#define X_MIN_PIN          -1
#define X_MAX_PIN          -1

#define Y_STEP_PIN         -1
#define Y_DIR_PIN          -1
#define Y_ENABLE_PIN       -1
#define Y_MIN_PIN          -1
#define Y_MAX_PIN          -1

#define Z_STEP_PIN         34
#define Z_DIR_PIN          32
#define Z_ENABLE_PIN       33
#define Z_MIN_PIN          13
#define Z_MAX_PIN          -1

#define E0_STEP_PIN         16
#define E0_DIR_PIN          35
#define E0_ENABLE_PIN       17

#define FAN_PIN            15  // Fan

#define SDPOWER            -1
#define SDSS               -1
#define LED_PIN            -1
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN          21
  #define MISO_PIN         22
  #define MOSI_PIN         23
#endif

#endif

#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, 
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, LED_PIN, PS_ON_PIN, \
                        FAN_PIN, LASER_PIN,          \
                        _E0_PINS _E1_PINS _E2_PINS }
#endif
