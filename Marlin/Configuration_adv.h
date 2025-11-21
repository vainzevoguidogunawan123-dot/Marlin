/**
 * Configuration_adv.h
 * Tailored for Marlin bugfix-2.1.x
 * Target: GD32F303RET6 (Creality v4.2.2 clone)
 * Dual Z on split cable (both motors on same driver) - no dual-driver defines
 *
 * This file enables runtime and advanced features:
 *  - Klipper-style Pressure Advance (runtime)
 *  - Input Shaping (software-mode placeholders)
 *  - UBL runtime helpers
 *  - Babystepping, Advanced Pause, Power-loss, EEPROM
 *  - Motor current placeholders and stepper tuning notes
 *
 * Review comments and adjust currents, accelerations, shaping params and
 * accelerometer options if you later add a physical sensor.
 */

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// --------------------------------------------------------------------------
// Runtime / motion tuning
// --------------------------------------------------------------------------

// Use Junction-Deviation motion planning (recommended)
#define JUNCTION_DEVIATION
#define DEFAULT_JUNCTION_DEVIATION 0.02  // tune if needed (0.02 is a safe default)

// S-curve acceleration (smoother acceleration profile)
#define S_CURVE_ACCELERATION
#define S_CURVE_ACCELERATIONS 16

// Junction / jerk defaults are set in Configuration.h - keep here as fallback
//#define DEFAULT_XJERK 10.0
//#define DEFAULT_YJERK 10.0
//#define DEFAULT_ZJERK 0.4

// --------------------------------------------------------------------------
// Pressure Advance (Klipper-style) - runtime editable
// --------------------------------------------------------------------------
// We enabled KLIPPER_STYLE_PRESSURE_ADVANCE in Configuration.h.
// This section exposes runtime support in Configuration_adv.
#ifdef KLIPPER_STYLE_PRESSURE_ADVANCE
  #define PRESSURE_ADVANCE
  // DEFAULT_PRESSURE_ADVANCE set in Configuration.h
  // Allow editable Pressure Advance via UI/G-codes
  #define EDITABLE_PRESSURE_ADVANCE
#endif

// --------------------------------------------------------------------------
// Input Shaping
// --------------------------------------------------------------------------
// We provide software-mode Input Shaping knobs. If you later add a sensor
// (ADXL345/other) enable accelerometer-based shaping below and configure pins.
#ifdef INPUT_SHAPING

  // Enable shaping runtime tuner (exposed via UI when INPUT_SHAPING_MENU present)
  #define SHAPING_TUNER_ENABLE

  // Software-only defaults (tweak these based on measured resonance)
  #define INPUT_SHAPING_FREQ  30.0    // nominal frequency (Hz)
  #define INPUT_SHAPING_DAMPING 0.15  // damping factor

  // If you add an accelerometer (e.g., ADXL345), you can enable:
  //#define USE_ADXL345
  //#define ACCELEROMETER_ADXL345
  //#define ADXL345_I2C_ADDRESS 0x53

  // UI support (requires EXTENSIBLE_UI + INPUT_SHAPING_MENU in Configuration.h)
  #ifdef INPUT_SHAPING_MENU
    #define INPUT_SHAPING_UI_ENABLED
    // allow runtime shape selection
    #define INPUT_SHAPING_ENABLE_FFT
  #endif
#endif

// --------------------------------------------------------------------------
// Unified Bed Leveling (UBL) helpers
// --------------------------------------------------------------------------
#ifdef AUTO_BED_LEVELING_UBL
  // Mesh validation and editing helpers
  #define UBL_G26_MESH_VALIDATION
  #define UBL_CLEAR_BED_AFTER_PROBE
  #define UBL_MESH_EDIT_GFX_OVERLAY
  #define UBL_MESH_EDIT_GFX_OVERLAY_FLIP 0
  // Allow storing meshes to EEPROM
  #define UBL_SAVE_MESH_EEPROM
#endif

// --------------------------------------------------------------------------
// Babystepping & Z tweaks
// --------------------------------------------------------------------------
#define BABYSTEPPING
#define BABYSTEP_ZPROBE_GFX_OVERLAY
// Starting babystep amount in mm (UI default)
#define BABYSTEP_INCREMENT 0.002

// --------------------------------------------------------------------------
// Advanced Pause / Filament change
// --------------------------------------------------------------------------
#define ADVANCED_PAUSE_FEATURE
#define PAUSE_PARK_RETRACT_FEEDRATE 60
#define FILAMENT_CHANGE_UNLOAD_FEEDRATE 60
#define FILAMENT_CHANGE_LOAD_FEEDRATE 50

// --------------------------------------------------------------------------
// Power Loss and EEPROM
// --------------------------------------------------------------------------
#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define POWER_LOSS_RECOVERY

// --------------------------------------------------------------------------
// Fans & PWM
// --------------------------------------------------------------------------
#define FAN_SOFT_PWM
#define FAN_MIN_PWM 50
#define FAN_KICKSTART_TIME 100

// --------------------------------------------------------------------------
// Thermal protections (recommended to keep enabled)
// --------------------------------------------------------------------------
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED
#define WATCH_TEMP_PERIOD 1
#define WATCH_TEMP_INCREASE 2

// --------------------------------------------------------------------------
// Stepper / motor current placeholders
//  - Set actual values per your motors and drivers
//  - For GD32/Creality boards with TMC/driver presets, map them in pins/board files
// --------------------------------------------------------------------------
#define MOTOR_CURRENT_PWM_DEFAULT 800 // mA example (override for real hardware)
#define DEFAULT_STEPPER_DEACTIVE_TIME 60

// --------------------------------------------------------------------------
// Acceleration smoothing / planner extras
// --------------------------------------------------------------------------
#define SKEW_CORRECTOR
#define MINIMUM_STEPPER_PULSE 1

// --------------------------------------------------------------------------
// Advanced features to make UI friendly
// --------------------------------------------------------------------------
#define PROGRESS_BAR
#define JSON_OUTPUT
#define HOST_KEEPALIVE_FEATURE
#define EXTENSIBLE_UI
#define INPUT_SHAPING_MENU
#define PROBE_OFFSET_WIZARD
#define PROBE_OFFSET_WIZARD_START_Z 0.0
#define PREHEAT_SHORTCUT_MENU
#define EDITABLE_PRESSURE_ADVANCE

// --------------------------------------------------------------------------
// Extruder / retraction advanced
// --------------------------------------------------------------------------
#define ADVANCED_PAUSE_RETRACT_Z_LIFT 2.0
#define PAUSE_PARK_NOZZLE_UP 2.0

// --------------------------------------------------------------------------
// BLTouch / probe runtime options (if BLTOUCH enabled in Configuration.h)
// --------------------------------------------------------------------------
#ifdef BLTOUCH
  #define BLTOUCH_DELAY 500
  #define BLTOUCH_SET_5V_MODE
#endif

// --------------------------------------------------------------------------
// Endstop / Probe sanity helpers
// --------------------------------------------------------------------------
// If your board uses weird pins, change in pins variant; SanityCheck expects these
#define Z_SAFE_HOMING
#define Z_SAFE_HOMING_X_POINT (X_MIN_POS + X_MAX_POS) / 2
#define Z_SAFE_HOMING_Y_POINT (Y_MIN_POS + Y_MAX_POS) / 2

// --------------------------------------------------------------------------
// Undefine features incompatible with split-cable Dual Z
// (Split-cable: both Z motors wired in parallel on same driver — DO NOT enable
// dual-driver or dual-endstop features)
// --------------------------------------------------------------------------
// Make sure these are NOT enabled:
// #define Z2_DRIVER_TYPE ...
// #define Z_DUAL_STEPPER_DRIVERS
// #define Z_TWO_STEPPER_DRIVERS
// #define Z_DUAL_ENDSTOPS
// Keep both motors tied to the same stepper driver in wiring instead.

// --------------------------------------------------------------------------
// Sanity check and compiler flags adjustments
// --------------------------------------------------------------------------
#define DISABLE_M503 // optionally speed up startup for actions; remove if you want M503 at boot

// --------------------------------------------------------------------------
// Helpful debug / developer options (comment out if not needed)
// --------------------------------------------------------------------------
//#define DEBUG_LEVELING_FEATURE
//#define DEBUG_LEVELING_FEATURE_EEPROM

// --------------------------------------------------------------------------
// Final notes & placeholders
// --------------------------------------------------------------------------
/*
 * TUNE PROCEDURE (recommended):
 * 1. Build with these settings to ensure compile passes.
 * 2. Flash to board and test homing, endstops, heater and thermistor.
 * 3. Tune PID for hotend and bed if needed.
 * 4. Tune junction_deviation/acceleration and input shaping frequency once you have an accelerometer or printed test patterns.
 *
 * If you later install a hardware accelerometer (ADXL345 etc.), update INPUT_SHAPING section and enable sensor define.
 */

#endif // CONFIGURATION_ADV_H
