/**
 * @file can_defs.hpp
 * @author Riley (rjm0037@uah.edu)
 * @author David (ds0196@uah.edu)
 * @brief CAN message definitions for VicCAN
 *
 */
#pragma once

#ifdef ARDUINO
#   include "Arduino.h"
#else
#   include <cstdint>
#endif

// X Macros for VicCAN data types
// Each entry is: X(NAME, VALUE, DOCSTRING)
// Used to generate both C++ enum definitions and pybind11 bindings from one
// source. To change things, only edit this file

// Helper macros for enum generation
#define UNILIB_ENUM_VALUE(NAME, VALUE, DOC) NAME = VALUE,
#define UNILIB_ENUM_COUNT(NAME, VALUE, DOC) +1

#define VICCAN_COMMANDS(X)                                                      \
    /* General (1-15) */                                                        \
    X(CMD_PING, 1,                                                              \
      "ID=1  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: DOUBLE - 1 (confirmation)")                                        \
    X(CMD_TIME, 2,                                                              \
      "ID=2  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: DOUBLE - millis() timestamp")                                      \
    X(CMD_B_LED, 3,                                                             \
      "ID=3  | General\n"                                                       \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(CMD_SENSOR_RECON, 4,                                                      \
      "ID=4  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    X(CMD_HEARTBEAT, 5,                                                         \
      "ID=5  | General\n"                                                       \
      "Send: FLOAT32 x2 - [count, uptime]\n"                                    \
      "Recv: EMPTY")                                                            \
    X(CMD_ALL_STOP, 6,                                                          \
      "ID=6  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    /* 7-15: reserved */                                                        \
                                                                                \
    /* REV Motor Control (16-23) */                                             \
    X(CMD_REV_STOP, 16,                                                         \
      "ID=16 | REV Motor Control\n"                                             \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    X(CMD_REV_IDENTIFY, 17,                                                     \
      "ID=17 | REV Motor Control\n"                                             \
      "Send: DOUBLE - motor ID\n"                                               \
      "Recv: EMPTY")                                                            \
    X(CMD_REV_IDLE_MODE, 18,                                                    \
      "ID=18 | REV Motor Control\n"                                             \
      "Send: DOUBLE - brake mode\n"                                             \
      "Recv: EMPTY")                                                            \
    X(CMD_REV_SET_DUTY, 19,                                                     \
      "ID=19 | REV Motor Control\n"                                             \
      "Send: DOUBLE (CITADEL fan) | FLOAT32 (core duty cycles) | "              \
      "INT16 (arm duty cycle)\n"                                                \
      "Recv: EMPTY")                                                            \
    X(CMD_REV_SET_VELOCITY, 20,                                                 \
      "ID=20 | REV Motor Control\n"                                             \
      "Send: FLOAT32 x2 - [motor0_rpm, motor1_rpm]\n"                           \
      "Recv: EMPTY")                                                            \
    /* 21-23: reserved */                                                       \
                                                                                \
    /* Misc Physical Control (24-31) */                                         \
    X(CMD_LSS_TURNBY_DEG, 24,                                                   \
      "ID=24 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - -1=lower, 0=stop, 1=raise (changing to FLOAT32)\n"        \
      "Recv: EMPTY")                                                            \
    X(CMD_PWMSERVO_SET_DEG, 25,                                                 \
      "ID=25 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - position (0-255)\n"                                       \
      "Recv: EMPTY")                                                            \
    X(CMD_DCMOTOR_CTRL, 26,                                                     \
      "ID=26 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - speed and direction\n"                                    \
      "Recv: EMPTY")                                                            \
    X(CMD_STEPPER_CTRL, 27,                                                     \
      "ID=27 | Misc Physical Control\n"                                         \
      "Send: TBD\n"                                                             \
      "Recv: EMPTY")                                                            \
    X(CMD_LASER_CTRL, 28,                                                       \
      "ID=28 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(CMD_LSS_RESET, 29,                                                        \
      "ID=29 | Misc Physical Control\n"                                         \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    /* 30-31: reserved */                                                       \
                                                                                \
    /* Submodule-specific (32-47) */                                            \
    X(CMD_ARM_IK_CTRL, 32,                                                      \
      "ID=32 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - target angles per joint in degrees*10\n"                \
      "Recv: EMPTY")                                                            \
    X(CMD_ARM_IK_TTG, 33,                                                       \
      "ID=33 | Submodule (Arm)\n"                                               \
      "Send: DOUBLE - time to goal in milliseconds\n"                           \
      "Recv: EMPTY")                                                            \
    X(CMD_DIGIT_LINAC_CTRL, 34,                                                 \
      "ID=34 | Submodule (Digit)\n"                                             \
      "Send: DOUBLE - direction/speed\n"                                        \
      "Recv: EMPTY")                                                            \
    X(CMD_DIGIT_WRIST_ROLL, 35,                                                 \
      "ID=35 | Submodule (Digit)\n"                                             \
      "Send: DOUBLE - direction/speed\n"                                        \
      "Recv: EMPTY")                                                            \
    X(CMD_DIGIT_IK_CTRL, 36,                                                    \
      "ID=36 | Submodule (Digit)\n"                                             \
      "Send: FLOAT32 x2 - [mode (0=manual, 1=ik), direction or target angle]\n" \
      "Recv: EMPTY")                                                            \
    X(CMD_FAERIE_SKAKE, 37,                                                     \
      "ID=37 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - direction\n"                                              \
      "Recv: EMPTY")                                                            \
    X(CMD_FAERIE_UVLED, 38,                                                     \
      "ID=38 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(CMD_ARM_MANUAL, 39,                                                       \
      "ID=39 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - directions [ax0, ax1, ax2, ax3]\n"                      \
      "Recv: EMPTY")                                                            \
    X(CMD_CITADEL_FAN_CTRL, 40,                                                 \
      "ID=40 | Submodule (CITADEL)\n"                                           \
      "Send: DOUBLE (valve_selection) | FLOAT32 (tube_id, milliliters) | "      \
      "INT16 (distributor_id x3)\n"                                             \
      "Recv: EMPTY")                                                            \
    X(CMD_CORE_TURN_TO, 41,                                                     \
      "ID=41 | Submodule (Core)\n"                                              \
      "Send: FLOAT32 x2 - [direction (0-360 deg), timeout (seconds)]\n"         \
      "Recv: EMPTY")                                                            \
    X(CMD_FAERIE_LINEAR_AC, 42,                                                 \
      "ID=42 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - -1=retract, 0=stop, 1=extend (changing to FLOAT32)\n"     \
      "Recv: EMPTY")                                                            \
    X(CMD_ARM_IK_TARGET_VELOCITY, 43,                                           \
      "ID=43 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - target velocities per joint in (deg/s)*10\n"            \
      "Recv: EMPTY")                                                            \
    X(CMD_FIRE_LIBS, 44,                                                        \
      "ID=44 | Submodule (LIBS)\n"                                              \
      "Send: DOUBLE - fire the LIBS laser\n"                                    \
      "Recv: EMPTY")                                                            \
    /* 45-47: reserved */                                                       \
                                                                                \
    /* Feedback (48-63) */                                                      \
    X(CMD_GNSS_LAT, 48,                                                         \
      "ID=48 | Feedback\n"                                                      \
      "Recv: DOUBLE - latitude in degrees")                                     \
    X(CMD_GNSS_LON, 49,                                                         \
      "ID=49 | Feedback\n"                                                      \
      "Recv: DOUBLE - longitude in degrees")                                    \
    X(CMD_GNSS_SAT, 50,                                                         \
      "ID=50 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [num_satellites, altitude_meters]")                   \
    X(CMD_DATA_IMU_GYRO, 51,                                                    \
      "ID=51 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [x, y, z, calib_status (sys|gyro|accel|mag)]")          \
    X(CMD_DATA_IMU_ACCEL_HEADING, 52,                                           \
      "ID=52 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [x, y, z, heading]")                                    \
    X(CMD_REVMOTOR_FEEDBACK, 53,                                                \
      "ID=53 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [motor_id, temp*10, voltage*10, current*10]")           \
    X(CMD_POWER_VOLTAGE, 54,                                                    \
      "ID=54 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [vbatt*100, 12v*100, 5v*100, 3v3*100]")                 \
    X(CMD_ARM_ENCODER_ANGLES, 55,                                               \
      "ID=55 | Feedback\n"                                                      \
      "Recv: INT16 x4 - joint positions in degrees*10")                         \
    X(CMD_DATA_BMP, 56,                                                         \
      "ID=56 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [temperature_C, altitude_m, pressure_hPa, unused]")     \
    X(CMD_SHT_TEMP_HUM, 57,                                                     \
      "ID=57 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [temperature, humidity]")                             \
    X(CMD_REV_POS_VEL_FEEDBACK, 58,                                             \
      "ID=58 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [position_rotations, velocity_rpm]")                  \
    X(CMD_DIGIT_LSS_FEEDBACK, 59,                                               \
      "ID=59 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [temp, current, unused, unused]")                       \
    X(CMD_JOINT_VELOCITIES, 60,                                                 \
      "ID=60 | Feedback\n"                                                      \
      "Recv: INT16 x4 - joint velocities in (deg/s)*100")                       \
    /* 61-63: reserved */

#define VICCAN_MICROCONTROLLERS(X)                       \
    X(MCU_BROADCAST, 0, "Target all MCUs")               \
    X(MCU_CORE, 1, "Core (navigation/drive)")            \
    X(MCU_ARM, 2, "Arm submodule")                       \
    X(MCU_DIGIT, 3, "Digit end-effector")                \
    X(MCU_FAERIE, 4, "FAERIE science submodule")         \
    X(MCU_CITADEL, 5, "CITADEL fluid control submodule") \
    X(MCU_LIBS, 6, "LIBS laser submodule")

#define VICCAN_DATA_TYPES(X)                                 \
    X(DT_1f64, 0, "1x double  - 8 bytes big-endian (>d)")    \
    X(DT_2f32, 1, "2x float32 - 8 bytes big-endian (>ff)")   \
    X(DT_4i16, 2, "4x int16   - 8 bytes big-endian (>hhhh)") \
    X(DT_NONE, 3, "No payload - 0 bytes")

namespace unilib {

// VicCAN Message Types enum
enum CanCmdId : uint8_t {
    VICCAN_COMMANDS(UNILIB_ENUM_VALUE)
};

// VicCAN Microcontroller IDs enum
enum class CanMcuId : uint8_t {
    VICCAN_MICROCONTROLLERS(UNILIB_ENUM_VALUE)
};

// VicCAN Data Types enum
// Possible datatypes for a VicCAN frame; decides how to decode/encode data
enum class CanDataType : uint8_t {
    VICCAN_DATA_TYPES(UNILIB_ENUM_VALUE)
};

}  // namespace unilib
