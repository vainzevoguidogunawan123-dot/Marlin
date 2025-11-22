/* Configuration_adv.h
   Performance & features for Ender-3 Pro custom build
*/

// ---- Motion & extrusion ----
#define JUNCTION_DEVIATION_MM 0.02

// Linear Advance (direct drive tuning)
#if ENABLED(LIN_ADVANCE)
  #define LIN_ADVANCE_K 0.15   // starting value; tune with test prints
#endif

// Babystepping for Z fine-tune during print
#define BABYSTEPPING
#define BABYSTEP_DISPLAY_TOTAL

// --- Dual Z auto-align (requires probe) ---
#define Z_STEPPER_AUTO_ALIGN
#ifndef NUM_Z_STEPPERS
  #define NUM_Z_STEPPERS 2
#endif
#define HOME_AFTER_G34
#define Z_STEPPER_AUTO_ALIGN_X_FIRST  40
#define Z_STEPPER_AUTO_ALIGN_Y_FIRST  40
#define Z_STEPPER_AUTO_ALIGN_X_SECOND 40
#define Z_STEPPER_AUTO_ALIGN_Y_SECOND 180

// --- Input Shaper (optional; needs accelerometer) ---
// #define INPUT_SHAPER
// #if ENABLED(INPUT_SHAPER)
//   #define SHAPER_FREQ_1 40.0
// #endif

// --- Safety & power ---
#define POWER_CHECK
#define HAS_POWER_SWITCH

// --- Filament change & park ---
#define ADVANCED_PAUSE_FEATURE
#define NOZZLE_PARK_FEATURE
#define FILAMENT_CHANGE_FEATURE

// --- TMC / driver settings ---
// If you plan to use sensorless homing with TMC, configure drivers here.
// For stock A4988 do not enable TMC-specific options.

// End of Configuration_adv.h
