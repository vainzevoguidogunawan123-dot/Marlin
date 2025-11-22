/* Configuration.h
   Marlin bugfix-2.1.x
   Custom for Ender-3 Pro (Creality V4.2.2 GD32F303)
   Hardware:
    - Dual Z motors (split cable)
    - X/Y linear rails (MGN12H)
    - Direct drive extruder (BMG/Orbiter-style assumed)
    - Hardened nozzle / bi-metal throat
*/

/*** --- YOU MUST EDIT BEFORE BUILD --- ***
 * Set the MOTHERBOARD macro below to match your board env or the board macro supported by this Marlin build.
 * If unsure, leave as-is and edit platformio.ini to select the correct env before building (see README in this message).
 */
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_CREALITY_V4_2_2   // <-- UBAH jika board macro di Marlin berbeda. Lihat catatan di README.
#endif

#define MACHINE_NAME "Ender-3 Pro - Custom (v4.2.2 GD32F303)"
#define EXTRUDERS 1

// Build volume
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 250

// Steps per unit (awal) - E harus dikalibrasi setelah pemasangan direct drive
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.00, 80.00, 400.00, 415.00 } // X, Y, Z, E (415 hanya contoh untuk direct drive; kalibrasi wajib)

// Motion tuning (lebih agresif karena linear rail)
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }   // mm/s
#define DEFAULT_MAX_ACCELERATION      { 3500, 3500, 200, 10000 } // X,Y,Z,E
#define DEFAULT_RETRACT_ACCELERATION  3000
#define JUNCTION_DEVIATION_MM         0.02

// Endstops
#define ENDSTOPPULLUPS
#define X_MIN_ENDSTOP_INVERTING false
#define Y_MIN_ENDSTOP_INVERTING false
#define Z_MIN_ENDSTOP_INVERTING false

// Thermistors
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1
#define HEATER_0_MINTEMP 5
#define BED_MINTEMP 5

// --- Probing / Bed leveling ---
// Jika kamu TIDAK punya probe, biarkan AUTO_BED_LEVELING_BILINEAR tapi sembunyikan probe define.
// Jika ada BLTouch/CR-Touch: uncomment block di bawah dan set NOZZLE_TO_PROBE_OFFSET
//#define BLTOUCH
//#define NOZZLE_TO_PROBE_OFFSET { -44, -9, 0 } // contoh; sesuaikan dengan mountmu

#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28
#define GRID_MAX_POINTS_X 5
#define GRID_MAX_POINTS_Y 5
#define BED_MESH_MAX_POINTS_X 5

// Save mesh to EEPROM
#define EEPROM_SETTINGS

// --- Dual Z support ---
// Karena kamu menggunakan dual-Z split cable, paling sering kedua motor di-paralel ke driver Z (tidak perlu config).
// Namun jika second Z terpasang ke driver terpisah, aktifkan Z multi driver support di Configuration_adv.h
//#define Z_DUAL_STEPPER_DRIVERS  // uncomment only if Z2 has separate driver pins

// --- Filament runout (opsional) ---
//#define FILAMENT_RUNOUT_SENSOR
//#define FILAMENT_RUNOUT_PULLUP
//#define FILAMENT_RUNOUT_DISTANCE_MM 7

// --- Extruder / Retraction defaults untuk direct drive ---
#define DEFAULT_RETRACTION_LENGTH 0.6
#define DEFAULT_RETRACTION_SPEED 40

// Linear Advance (aktifkan di Configuration_adv.h)
#define LIN_ADVANCE

// LCD / UI: biarkan default Creality 12864 jika pakai stock LCD
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

// Safety
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED
