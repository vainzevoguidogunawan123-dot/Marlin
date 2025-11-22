Marlin/Configuration.h
/**
 * Configuration.h — Ender-3 Pro
 * Board: Creality V4.2.2 (GD32F303)
 * Firmware: Marlin bugfix-2.1.x
 */

#pragma once

#define CONFIGURATION_H_VERSION 02010300

#define MOTHERBOARD BOARD_CREALITY_V4_2_2
#define SERIAL_PORT 1
#define BAUDRATE 115200

#define MACHINE_NAME "Ender3Pro Custom (GD32F303)"
#define EXTRUDERS 1

// ——————————————————
// Bed size
// ——————————————————
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 250

// ——————————————————
// Linear Rail X/Y, Dual Z Split Cable
// ——————————————————
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.0, 80.0, 400.0, 415.0 }
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }
#define DEFAULT_MAX_ACCELERATION      { 3500, 3500, 200, 10000 }
#define DEFAULT_RETRACT_ACCELERATION  3000
#define JUNCTION_DEVIATION_MM         0.02
#define DEFAULT_EJERK                 5.0

// ——————————————————
// Endstop
// ——————————————————
#define ENDSTOPPULLUPS
#define X_MIN_ENDSTOP_INVERTING false
#define Y_MIN_ENDSTOP_INVERTING false
#define Z_MIN_ENDSTOP_INVERTING false

// ——————————————————
// Thermistors
// ——————————————————
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1
#define HEATER_0_MINTEMP 5
#define BED_MINTEMP 5

// ——————————————————
// Bed Leveling
// ——————————————————
#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28
#define GRID_MAX_POINTS_X 5
#define GRID_MAX_POINTS_Y 5
#define Z_SAFE_HOMING
#define EEPROM_SETTINGS

// ——————————————————
// Direct Drive Retraction
// ——————————————————
#define DEFAULT_RETRACTION_LENGTH 0.6
#define DEFAULT_RETRACTION_SPEED 40

// ——————————————————
// Linear Advance (K akan diatur di adv)
// ——————————————————
#define LIN_ADVANCE
#define MARLIN_TEST_BUILD
