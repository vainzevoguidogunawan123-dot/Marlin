/**
 * Configuration_adv.h — Ender-3 Pro Custom
 * Board: Creality V4.2.2 GD32
 */

#pragma once

#define CONFIGURATION_ADV_H_VERSION 02010300

// ——————————————————
// Linear Advance
// ——————————————————
#if ENABLED(LIN_ADVANCE)
  #define LIN_ADVANCE_K 0.15
#endif

// ——————————————————
// Babystepping
// ——————————————————
#define BABYSTEPPING
#define BABYSTEP_DISPLAY_TOTAL

// ——————————————————
// Dual Z Alignment (jika suatu hari pakai 2 driver)
// ——————————————————
#define Z_STEPPER_AUTO_ALIGN
#ifndef NUM_Z_STEPPERS
  #define NUM_Z_STEPPERS 2
#endif

// ——————————————————
// Filament change
// ——————————————————
#define ADVANCED_PAUSE_FEATURE
#define FILAMENT_CHANGE_FEATURE
#define NOZZLE_PARK_FEATURE

// ——————————————————
// Extra safety
// ——————————————————
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

// ——————————————————
// Optional: Input Shaper (HANYA jika ada accelerometer)
// ——————————————————
//#define INPUT_SHAPER
//#define SHAPER_FREQ_1 40

