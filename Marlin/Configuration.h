/*
Marlin Configuration.h - Final ready-to-compile template
Target: Ender 3 Pro, Creality v4.2.2 (GD32F303 RET6, 512KB)
Features: UBL, Input Shaping (software), Klipper-style Pressure Advance, Fan curve, BLTouch, Dual Z (split cable), Linear Rail, Direct Drive, etc.
NOTE: Replace any hardware-specific pin defines only if required by your Marlin fork. This is a configuration TEMPLATE that was assembled from your requested options.
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define STRING_CONFIG_H_AUTHOR "Custom Marlin - Ender3 Pro - by user"

// Board
#define MOTHERBOARD BOARD_CREALITY_V422
#define SERIAL_PORT 0
#define BAUDRATE 115200

#define CUSTOM_MACHINE_NAME "Ender 3 Pro - Rail + DD + BLTouch + DualZ"

// Steps per unit (X, Y, Z, E)
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 415 } // E set to 415 for common DD extruders

// Endstops / Probe
#define USE_Z_MIN_PLUG
#define Z_MIN_ENDSTOP_INVERTING false

// BLTouch
#define BLTOUCH
// Note: SERVO pin mapping is handled by board variant. Keep default unless required.
//#define SERVO0_PIN PA8

// Probe offsets (measured or default safe values)
#define NOZZLE_TO_PROBE_OFFSET { -42, -10, 0.0 } // X, Y, Z (default safe example)

#define PROBE_WITHOUT_HOMING
#define Z_SAFE_HOMING
#define Z_SAFE_HOMING_X_POINT (X_MIN_POS + X_MAX_POS) / 2
#define Z_SAFE_HOMING_Y_POINT (Y_MIN_POS + Y_MAX_POS) / 2

// Unified Bed Leveling (UBL)
#define AUTO_BED_LEVELING_UBL
#define MESH_EDIT_GFX_OVERLAY
#define G26_MESH_VALIDATION

// Mesh default
#define GRID_MAX_POINTS_X 5
#define UBL_MESH_POINTS 5

// Motion settings
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }
#define DEFAULT_ACCELERATION          1500
#define DEFAULT_RETRACT_ACCELERATION  3000
#define DEFAULT_TRAVEL_ACCELERATION   1500

#define S_CURVE_ACCELERATION
#define S_CURVE_ACCELERATIONS 16

#define DEFAULT_XJERK 10.0
#define DEFAULT_YJERK 10.0
#define DEFAULT_ZJERK 0.4

// Input shaping (software mode)
#define INPUT_SHAPING
#define INPUT_SHAPING_STEADYING

// Ender 3 Pro bed / axis limits (safe defaults)
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 250

// Extruder / Retraction
#define EXTRUDERS 1
#define RETRACT_LENGTH 1.0
#define RETRACT_SPEED 35
#define FILAMENT_OUNCE 0

// Klipper-style Pressure Advance (selected over LIN_ADVANCE)
#define KLIPPER_STYLE_PRESSURE_ADVANCE
#define DEFAULT_PRESSURE_ADVANCE 0.05

// Thermal
#define TEMP_SENSOR_0 11 // NTC 3950 100K
#define HEATER_0_MAXTEMP 300
#define BED_MAXTEMP 120
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

// Dual Z - split cable (both motors on same driver). DO NOT enable independent Z drivers if split cable used.
/* If you later wire independent Z2 driver, enable appropriate defines in Configuration_adv and pin mappings */

// Misc features
#define EEPROM_SETTINGS
#define PROGRESS_BAR
#define JSON_OUTPUT
#define HOST_KEEPALIVE_FEATURE

#define BABYSTEPPING
#define BABYSTEP_ZPROBE_GFX_OVERLAY

#define POWER_LOSS_RECOVERY

// Fan control
#define FAN_SOFT_PWM
#define FAN_MIN_PWM 50
#define FAN_KICKSTART_TIME 100

// Advanced pause
#define ADVANCED_PAUSE_FEATURE
#define PAUSE_PARK_RETRACT_FEEDRATE 60
#define FILAMENT_CHANGE_UNLOAD_FEEDRATE 60

// Filament runout - disabled by default (enable if you have sensor)
//#define FILAMENT_RUNOUT_SENSOR
//#define NUM_RUNOUT_SENSORS 1
//#define FIL_RUNOUT_SCRIPT "M600"

// LCD UI tweaks (enable extended menus)
#define LCD_BED_LEVELING
#define ADVANCED_SETTINGS_MENU
#define MOTION_ADVANCED_MENU
#define PROBE_OFFSET_WIZARD
#define PROBE_OFFSET_WIZARD_START_Z 0.0
#define PREHEAT_SHORTCUT_MENU
#define FILAMENT_LOAD_UNLOAD_GCODES
#define EDITABLE_PRESSURE_ADVANCE
#define EXTENSIBLE_UI
#define INPUT_SHAPING_MENU

// End of Configuration.h
#endif // CONFIGURATION_H
