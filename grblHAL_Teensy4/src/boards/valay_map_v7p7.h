/*
  generic_map.h - driver code for IMXRT1062 processor (on Teensy 4.x board)

  Part of grblHAL

  Copyright (c) 2020-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 2
#error "Axis configuration is not supported!"
#endif

#if SPINDLE_SYNC_ENABLE
#error "Spindle sync is not supported"
#endif

// Define step pulse output pins.
#define X_STEP_PIN          (2u)
#define Y_STEP_PIN          (4u)
#define Z_STEP_PIN          (6u)

// Define step direction output pins.
#define X_DIRECTION_PIN     (3u)
#define Y_DIRECTION_PIN     (5u)
#define Z_DIRECTION_PIN     (7u)

// Define stepper driver enable/disable output pin(s).
#define STEPPERS_ENABLE_PIN (32u)


// Define homing/hard limit switch input pins.
#define X_LIMIT_PIN         (19u)
#define Y_LIMIT_PIN         (20u)
#define Z_LIMIT_PIN         (21u)

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN         (8u)
#define M3_DIRECTION_PIN    (9u)
#define M3_LIMIT_PIN        (22u)
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PIN         (10u)
#define M4_DIRECTION_PIN    (11u)
#define M4_LIMIT_PIN        (23u)
#if SPINDLE_STEPPER
// #define M4_ENABLE_PIN       (31u)
#define SPINDLE_ENABLE_PIN      (31u)
#endif
#endif

// Define driver spindle pins
#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PIN         (13u)
// #else
// #define AUXOUTPUT0_PIN          (13u)
#endif

#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PIN   (30u)
// #else
// #define AUXOUTPUT1_PIN          (11u)
#endif

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PIN      (31u)
// #else
// #define AUXOUTPUT2_PIN          (12u)
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PIN   (14u)
//#define COOLANT_MIST_PIN    (18u)

// Define user-control CONTROLs (cycle start, reset, feed hold, door) input pins.
#define RESET_PIN           (17u) // E-Stop
#define FEED_HOLD_PIN       (37u)
#define CYCLE_START_PIN     (38u)

// Define auxillary input pins
#define AUXINPUT0_PIN       (40u)
#define AUXINPUT1_PIN       (34u)
#define AUXINPUT2_PIN       (33u)
// #define AUXINPUT3_PIN       (37u)
// #define AUXINPUT4_PIN       (38u)

#define AUXINPUT5_PIN       (18u) // Probe
#define AUXINPUT6_PIN       (15u) // Safety door
#define AUXINPUT7_PIN       (16u) // Motor fault

#if PROBE_ENABLE
#define PROBE_PIN           AUXINPUT5_PIN //Assign like this, not pin number or it will not run
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN     AUXINPUT6_PIN
#endif

#if MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PIN     AUXINPUT7_PIN
#endif

#define AUXOUTPUT0_PIN      (29u) // Out1
#define AUXOUTPUT1_PIN      (28u) // Out2
#define AUXOUTPUT2_PIN      (27u) // Out3
#define AUXOUTPUT3_PIN      (26u) // Out4
#define AUXOUTPUT4_PIN      (12u) // Out5
#define AUXOUTPUT5_PIN      (35u) // Out6
#define AUXOUTPUT6_PIN      (36u) // Out7

#if I2C_ENABLE
#define I2C_PORT            4
#define I2C_SCL4            (24u) // Not referenced, for info only
#define I2C_SDA4            (25u) // Not referenced, for info only
#endif

#if QEI_ENABLE
#define QEI_A_PIN           (0)
#define QEI_B_PIN           (3)
#define QEI_SELECT_PIN      AUXINPUT2_PIN
#endif