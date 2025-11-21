/**
 * Configuration.h
 * Marlin 2.1.3 compatible template
 * Target: Ender 3 Pro style, Creality v4.2.2 (GD32F303RET6)
 * Features: UBL, BLTouch clone, Direct Drive (default steps), Input Shaping (software),
 *           Klipper-style Pressure Advance, Linear rails tuned (higher accel), etc.
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define STRING_CONFIG_H_AUTHOR "Custom Marlin - Ender3 - by user"

//======================== Basics ========================
#define MOTHERBOARD BOARD_CREALITY_V422
#define SERIAL_PORT 0
#define BAUDRATE 115200

#define CUSTOM_MACHINE_NAME "Ender 3 - LinearRail - DD - BLTouch"

//======================== Mechanical Settings ========================
// Ender 3 nominal dimensions
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 250

// Steps per unit (X, Y, Z, E)
// Using default Ender3-style steps; extruder left as default 93 (user requested Default)
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 93 }

// Endstop / homing
#define USE_Z_MIN_PLUG
#define Z_MIN_ENDSTOP_INVERTING false
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

//======================== Thermal ========================
#define TEMP_SENSOR_0 11   // Epcos/NTC 100K (as in your sample); adjust if needed
#define HEATER_0_MAXTEMP 300
#define BED_MAXTEMP 120
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

//======================== Extruder ========================
#define EXTRUDERS 1
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Retraction (tuned defaults for direct drive)
#define RETRACT_LENGTH 1.0
#define RETRACT_SPEED 35

//======================== Bed leveling / Probe ========================
#define BLTOUCH
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
// Probe offsets (example) - measure & tweak for your BLTouch mount
#define NOZZLE_TO_PROBE_OFFSET { -42, -10, 0.0 } // X, Y, Z (adjust as required)

#define PROBE_WITHOUT_HOMING
#define Z_SAFE_HOMING
#define Z_SAFE_HOMING_X_POINT ((X_MIN_POS + X_BED_SIZE) / 2)
#define Z_SAFE_HOMING_Y_POINT ((Y_MIN_POS + Y_BED_SIZE) / 2)

// Unified Bed Leveling
#define AUTO_BED_LEVELING_UBL
#define MESH_EDIT_GFX_OVERLAY
#define G26_MESH_VALIDATION
#define GRID_MAX_POINTS_X 5
#define UBL_MESH_POINTS 5

//======================== Motion / Speeds ========================
// Increased values for linear-rail X/Y; tune to motors/drivers
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }   // mm/s
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 } // mm/s^2
#define DEFAULT_ACCELERATION          1500
#define DEFAULT_RETRACT_ACCELERATION  3000
#define DEFAULT_TRAVEL_ACCELERATION   1500

// S-curve acceleration for smoother motion
#define S_CURVE_ACCELERATION
#define S_CURVE_ACCELERATIONS 16

#define DEFAULT_XJERK 10.0
#define DEFAULT_YJERK 10.0
#define DEFAULT_ZJERK 0.4

//======================== Input Shaping / Pressure Advance ========================
#define INPUT_SHAPING
#define INPUT_SHAPING_STEADYING

// Klipper-style Pressure Advance (runtime editable)
#define KLIPPER_STYLE_PRESSURE_ADVANCE
#define DEFAULT_PRESSURE_ADVANCE 0.05

//======================== Misc features ========================
#define EEPROM_SETTINGS
#define PROGRESS_BAR
#define JSON_OUTPUT
#define HOST_KEEPALIVE_FEATURE

#define BABYSTEPPING
#define BABYSTEP_ZPROBE_GFX_OVERLAY
// Required by some sanity checks
#define BABYSTEP_MULTIPLICATOR_Z 1

// Manual feedrates required for some UIs/skins
#define MANUAL_FEEDRATE
#define MANUAL_FEEDRATE_0  ( 20*60 )   // hotend
#define MANUAL_FEEDRATE_1  ( 20*60 )   // second nozzle (if any)
#define MANUAL_FEEDRATE_2  ( 20*60 )
#define MANUAL_FEEDRATE_3  ( 20*60 )

#define POWER_LOSS_RECOVERY

// Fan
#define FAN_SOFT_PWM
#define FAN_MIN_PWM 50
#define FAN_KICKSTART_TIME 100

// Advanced pause (filament change)
#define ADVANCED_PAUSE_FEATURE
#define PAUSE_PARK_RETRACT_FEEDRATE 60
#define FILAMENT_CHANGE_UNLOAD_FEEDRATE 60

// LCD / UI
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

// Safety / extras
#define JSON_OUTPUT_ENABLE
#define HOST_KEEPALIVE_FEATURE

//======================== End of Configuration ========================
#endif // CONFIGURATION_H
