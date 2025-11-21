// Placeholder Configuration_adv.h generated
/*
Marlin Configuration_adv.h - Final ready-to-compile template (extract)
Includes advanced runtime features tuning, input shaping placeholders, UBL settings, etc.
*/

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// Pressure Advance (Klipper-style) runtime editable
#ifdef KLIPPER_STYLE_PRESSURE_ADVANCE
  #define PRESSURE_ADVANCE
  // Default is set in Configuration.h as DEFAULT_PRESSURE_ADVANCE
#endif

// Input Shaping defaults (software-mode). If you later add ADXL345, enable accelerometer-based shaping.
#ifdef INPUT_SHAPING
  #define SHAPING_TUNER_ENABLE
  // Default shaping entries (example)
  #define INPUT_SHAPING_FREQ 30.0
  #define INPUT_SHAPING_DAMPING 0.15
#endif

// Junction deviation
#define JUNCTION_DEVIATION
#define DEFAULT_JUNCTION_DEVIATION 0.02

// Linear Advance note removed (we use Klipper-style PA)
//#define LIN_ADVANCE

// BABYSTEPPING options
#define BABYSTEP_ZPROBE_OFFSET

// UBL useful settings
#ifdef AUTO_BED_LEVELING_UBL
  #define UBL_G26_MESH_VALIDATION
  #define UBL_CLEAR_BED_AFTER_PROBE
  #define UBL_MESH_EDIT_GFX_OVERLAY
  #define UBL_MESH_EDIT_GFX_OVERLAY_FLIP 0
#endif

// Motor current / stepper settings placeholders - set per hardware later
#define MOTOR_CURRENT_PWM_DEFAULT 800 // mA example - tune per motors/drivers

// Thermal protections
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

// Filament change advanced
#define ADVANCED_PAUSE_FEATURE

// Input shaping menu and runtime knobs (exposed via LCD if EXTENSIBLE_UI + INPUT_SHAPING_MENU)
#ifdef INPUT_SHAPING_MENU
  // expose frequency and damping on UI
  #define INPUT_SHAPING_UI_ENABLED
#endif

// End of Configuration_adv.h
#endif // CONFIGURATION_ADV_H
