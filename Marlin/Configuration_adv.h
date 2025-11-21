/**
 * Configuration_adv.h
 * Marlin 2.1.3 compatible advanced settings
 */

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// ---------------- Pressure Advance (Klipper-style)
#ifdef KLIPPER_STYLE_PRESSURE_ADVANCE
  #define PRESSURE_ADVANCE
  // DEFAULT_PRESSURE_ADVANCE is set in Configuration.h
#endif

// ---------------- Input Shaping (software)
#ifdef INPUT_SHAPING
  // Enable UI tuners
  #define SHAPING_TUNER_ENABLE
  // Default shaping parameters (software-mode)
  #define INPUT_SHAPING_FREQ 30.0
  #define INPUT_SHAPING_DAMPING 0.15
  // Allow enabling/disabling on the fly via UI
#endif

// ---------------- Junction deviation
#define JUNCTION_DEVIATION
#define DEFAULT_JUNCTION_DEVIATION 0.02

// ---------------- Babystepping
#define BABYSTEP_MULTIPLICATOR_Z 1    // ensure sanity

// ---------------- UBL helpers
#ifdef AUTO_BED_LEVELING_UBL
  #define UBL_G26_MESH_VALIDATION
  #define UBL_CLEAR_BED_AFTER_PROBE
  #define UBL_MESH_EDIT_GFX_OVERLAY
  #define UBL_MESH_EDIT_GFX_OVERLAY_FLIP 0
#endif

// ---------------- Motor current / steppers placeholders
// Tune these in runtime or in build if you know exact currents
#define MOTOR_CURRENT_PWM_DEFAULT 800 // mA example

// ---------------- Thermal protections
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

// ---------------- Advanced Pause
#define ADVANCED_PAUSE_FEATURE

// ---------------- Input shaping UI (expose fields)
#ifdef INPUT_SHAPING_MENU
  #define INPUT_SHAPING_UI_ENABLED
#endif

// ---------------- Misc
#define STATUS_REPORT_NO_NEWLINE

#endif // CONFIGURATION_ADV_H
