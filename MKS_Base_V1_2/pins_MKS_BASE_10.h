/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS BASE 1.0 – Arduino Mega2560 with RAMPS v1.4 pin assignments
 *
 * Rev B - Override pin definitions for CASE_LIGHT and M3/M4/M5 spindle control
 */

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS BASE 1.0 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "MKS BASE 1.0"
#define MKS_BASE_VERSION 10

/**
 * Pin mapping for the 1280 and 2560
 *
 *   Hardware Pin  : 02 03 06 07 01 05 15 16 17 18 23 24 25 26 64 63 13 12 46 45 44 43 78 77 76 75 74 73 72 71 60 59 58 57 56 55 54 53 50 70 52 51 42 41 40 39 38 37 36 35 22 21 20 19 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 | 04 08 09 10 11 14 27 28 29 30 31 32 33 34 47 48 49 61 62 65 66 67 68 69 79 80 81 98 99 100
 *   Port          : E0 E1 E4 E5 G5 E3 H3 H4 H5 H6 B4 B5 B6 B7 J1 J0 H1 H0 D3 D2 D1 D0 A0 A1 A2 A3 A4 A5 A6 A7 C7 C6 C5 C4 C3 C2 C1 C0 D7 G2 G1 G0 L7 L6 L5 L4 L3 L2 L1 L0 B3 B2 B1 B0 F0 F1 F2 F3 F4 F5 F6 F7 K0 K1 K2 K3 K4 K5 K6 K7 | E2 E6 E7 xx xx H2 H7 G3 G4 xx xx xx xx xx D4 D5 D6 xx xx J2 J3 J4 J5 J6 J7 xx xx xx xx xx
 *   Logical Pin   : 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 | 78 79 80 xx xx 84 85 71 70 xx xx xx xx xx 81 82 83 xx xx 72 73 75 76 77 74 xx xx xx xx xx
 */

//
// Limit Switches
//
#ifndef X_STOP_PIN
  #ifndef X_MIN_PIN
    #define X_MIN_PIN                         65
  #endif
  #ifndef X_MAX_PIN
    #define X_MAX_PIN                         66
  #endif
#endif
#ifndef Y_STOP_PIN
  #ifndef Y_MIN_PIN
    #define Y_MIN_PIN                         11
  #endif
  #ifndef Y_MAX_PIN
    #define Y_MAX_PIN                         12
  #endif
#endif


//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN)
  #define SPINDLE_LASER_ENA_PIN              2  // Pullup or pulldown!
  #define SPINDLE_LASER_PWM_PIN              3  // Hardware PWM
  #define SPINDLE_DIR_PIN                   -1
#endif

#include "pins_MKS_BASE_common.h"
