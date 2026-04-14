#pragma once

#include <cstdint>

// X Macros for VicCAN data types
// Each entry is: X(NAME, VALUE, DOCSTRING)
// Used to generate both C++ enum definitions and pybind11 bindings from one
// source. To change things, only edit this file

// Helper macros for enum generation
#define UNILIB_ENUM_VALUE(NAME, VALUE, DOC) NAME = VALUE,
#define UNILIB_ENUM_COUNT(NAME, VALUE, DOC) +1

#define VICCAN_MESSAGE_TYPES(X)                                                 \
    /* General (1-15) */                                                        \
    X(PING, 1,                                                                  \
      "ID=1  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: DOUBLE - 1 (confirmation)")                                        \
    X(TIME, 2,                                                                  \
      "ID=2  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: DOUBLE - millis() timestamp")                                      \
    X(BUILTIN_LED_CTRL, 3,                                                      \
      "ID=3  | General\n"                                                       \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(SENSOR_RECONNECT, 4,                                                      \
      "ID=4  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    X(HEARTBEAT, 5,                                                             \
      "ID=5  | General\n"                                                       \
      "Send: FLOAT32 x2 - [count, uptime]\n"                                    \
      "Recv: EMPTY")                                                            \
    X(ALL_STOP, 6,                                                              \
      "ID=6  | General\n"                                                       \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    /* 7-15: reserved */                                                        \
                                                                                \
    /* REV Motor Control (16-23) */                                             \
    X(REV_STOP_ALL_MOTORS, 16,                                                  \
      "ID=16 | REV Motor Control\n"                                             \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    X(REV_IDENTIFY, 17,                                                         \
      "ID=17 | REV Motor Control\n"                                             \
      "Send: DOUBLE - motor ID\n"                                               \
      "Recv: EMPTY")                                                            \
    X(REV_IDLE_MODE, 18,                                                        \
      "ID=18 | REV Motor Control\n"                                             \
      "Send: DOUBLE - brake mode\n"                                             \
      "Recv: EMPTY")                                                            \
    X(REV_SET_DUTY_CYCLE, 19,                                                   \
      "ID=19 | REV Motor Control\n"                                             \
      "Send: DOUBLE (CITADEL fan) | FLOAT32 (core duty cycles) | "              \
      "INT16 (arm duty cycle)\n"                                                \
      "Recv: EMPTY")                                                            \
    X(REV_SET_VELOCITY, 20,                                                     \
      "ID=20 | REV Motor Control\n"                                             \
      "Send: FLOAT32 x2 - [motor0_rpm, motor1_rpm]\n"                           \
      "Recv: EMPTY")                                                            \
    /* 21-23: reserved */                                                       \
                                                                                \
    /* Misc Physical Control (24-31) */                                         \
    X(LSS_CONTROL, 24,                                                          \
      "ID=24 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - -1=lower, 0=stop, 1=raise (changing to FLOAT32)\n"        \
      "Recv: EMPTY")                                                            \
    X(PWM_SERVO_CONTROL, 25,                                                    \
      "ID=25 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - position (0-255)\n"                                       \
      "Recv: EMPTY")                                                            \
    X(DC_MOTOR_CONTROL, 26,                                                     \
      "ID=26 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - speed and direction\n"                                    \
      "Recv: EMPTY")                                                            \
    X(STEPPER_CONTROL, 27,                                                      \
      "ID=27 | Misc Physical Control\n"                                         \
      "Send: TBD\n"                                                             \
      "Recv: EMPTY")                                                            \
    X(LASER_CONTROL, 28,                                                        \
      "ID=28 | Misc Physical Control\n"                                         \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(LSS_RESET, 29,                                                            \
      "ID=29 | Misc Physical Control\n"                                         \
      "Send: EMPTY\n"                                                           \
      "Recv: EMPTY")                                                            \
    /* 30-31: reserved */                                                       \
                                                                                \
    /* Submodule-specific (32-47) */                                            \
    X(ARM_IK_TARGET_ANGLES, 32,                                                 \
      "ID=32 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - target angles per joint in degrees*10\n"                \
      "Recv: EMPTY")                                                            \
    X(ARM_IK_TIME_TO_GOAL, 33,                                                  \
      "ID=33 | Submodule (Arm)\n"                                               \
      "Send: DOUBLE - time to goal in milliseconds\n"                           \
      "Recv: EMPTY")                                                            \
    X(DIGIT_LINEAR_AC, 34,                                                      \
      "ID=34 | Submodule (Digit)\n"                                             \
      "Send: DOUBLE - direction/speed\n"                                        \
      "Recv: EMPTY")                                                            \
    X(DIGIT_WRIST_ROTATE, 35,                                                   \
      "ID=35 | Submodule (Digit)\n"                                             \
      "Send: DOUBLE - direction/speed\n"                                        \
      "Recv: EMPTY")                                                            \
    X(DIGIT_WRIST_YAW, 36,                                                      \
      "ID=36 | Submodule (Digit)\n"                                             \
      "Send: FLOAT32 x2 - [mode (0=manual, 1=ik), direction or target angle]\n" \
      "Recv: EMPTY")                                                            \
    X(FAERIE_SHAKE, 37,                                                         \
      "ID=37 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - direction\n"                                              \
      "Recv: EMPTY")                                                            \
    X(FAERIE_UV_LED, 38,                                                        \
      "ID=38 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - 0=off, 1=on\n"                                            \
      "Recv: EMPTY")                                                            \
    X(ARM_MANUAL_CONTROL, 39,                                                   \
      "ID=39 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - directions [ax0, ax1, ax2, ax3]\n"                      \
      "Recv: EMPTY")                                                            \
    X(CITADEL_SERVO_CTRL, 40,                                                   \
      "ID=40 | Submodule (CITADEL)\n"                                           \
      "Send: DOUBLE (valve_selection) | FLOAT32 (tube_id, milliliters) | "      \
      "INT16 (distributor_id x3)\n"                                             \
      "Recv: EMPTY")                                                            \
    X(CORE_TURN_TO, 41,                                                         \
      "ID=41 | Submodule (Core)\n"                                              \
      "Send: FLOAT32 x2 - [direction (0-360 deg), timeout (seconds)]\n"         \
      "Recv: EMPTY")                                                            \
    X(FAERIE_LINEAR_AC, 42,                                                     \
      "ID=42 | Submodule (FAERIE)\n"                                            \
      "Send: DOUBLE - -1=retract, 0=stop, 1=extend (changing to FLOAT32)\n"     \
      "Recv: EMPTY")                                                            \
    X(ARM_IK_TARGET_VELOCITY, 43,                                               \
      "ID=43 | Submodule (Arm)\n"                                               \
      "Send: INT16 x4 - target velocities per joint in (deg/s)*10\n"            \
      "Recv: EMPTY")                                                            \
    X(FIRE_LIBS, 44,                                                            \
      "ID=44 | Submodule (LIBS)\n"                                              \
      "Send: DOUBLE - fire the LIBS laser\n"                                    \
      "Recv: EMPTY")                                                            \
    /* 45-47: reserved */                                                       \
                                                                                \
    /* Feedback (48-63) */                                                      \
    X(GNSS_LATITUDE, 48,                                                        \
      "ID=48 | Feedback\n"                                                      \
      "Recv: DOUBLE - latitude in degrees")                                     \
    X(GNSS_LONGITUDE, 49,                                                       \
      "ID=49 | Feedback\n"                                                      \
      "Recv: DOUBLE - longitude in degrees")                                    \
    X(GNSS_SATELLITE_ALTITUDE, 50,                                              \
      "ID=50 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [num_satellites, altitude_meters]")                   \
    X(BNO_GYRO_CALIB_STATUS, 51,                                                \
      "ID=51 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [x, y, z, calib_status (sys|gyro|accel|mag)]")          \
    X(BNO_ACCEL_HEADING, 52,                                                    \
      "ID=52 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [x, y, z, heading]")                                    \
    X(REV_MOTOR_FEEDBACK, 53,                                                   \
      "ID=53 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [motor_id, temp*10, voltage*10, current*10]")           \
    X(BOARD_POWER_VOLTAGE, 54,                                                  \
      "ID=54 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [vbatt*100, 12v*100, 5v*100, 3v3*100]")                 \
    X(JOINT_POSITIONS, 55,                                                      \
      "ID=55 | Feedback\n"                                                      \
      "Recv: INT16 x4 - joint positions in degrees*10")                         \
    X(BMP_TEMP_ALT_PRESS, 56,                                                   \
      "ID=56 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [temperature_C, altitude_m, pressure_hPa, unused]")     \
    X(SHT_TEMP_HUM, 57,                                                         \
      "ID=57 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [temperature, humidity]")                             \
    X(REV_POS_VEL_FEEDBACK, 58,                                                 \
      "ID=58 | Feedback\n"                                                      \
      "Recv: FLOAT32 x2 - [position_rotations, velocity_rpm]")                  \
    X(DIGIT_LSS_FEEDBACK, 59,                                                   \
      "ID=59 | Feedback\n"                                                      \
      "Recv: INT16 x4 - [temp, current, unused, unused]")                       \
    X(JOINT_VELOCITIES, 60,                                                     \
      "ID=60 | Feedback\n"                                                      \
      "Recv: INT16 x4 - joint velocities in (deg/s)*100")                       \
    /* 61-63: reserved */

#define VICCAN_MICROCONTROLLERS(X)                   \
    X(BROADCAST, 0, "Target all MCUs")               \
    X(CORE, 1, "Core (navigation/drive)")            \
    X(ARM, 2, "Arm submodule")                       \
    X(DIGIT, 3, "Digit end-effector")                \
    X(FAERIE, 4, "FAERIE science submodule")         \
    X(CITADEL, 5, "CITADEL fluid control submodule") \
    X(LIBS, 6, "LIBS laser submodule")

#define VICCAN_DATA_TYPES(X)                               \
    X(DOUBLE, 0, "1x double  - 8 bytes big-endian (>d)")   \
    X(FLOAT32, 1, "2x float32 - 8 bytes big-endian (>ff)") \
    X(INT16, 2, "4x int16   - 8 bytes big-endian (>hhhh)") \
    X(EMPTY, 3, "No payload - 0 bytes")

namespace unilib {

// VicCAN Message Types enum
enum class MessageType : uint8_t {
    VICCAN_MESSAGE_TYPES(UNILIB_ENUM_VALUE)
};

// VicCAN Microcontroller IDs enum
enum class Microcontroller : uint8_t {
    VICCAN_MICROCONTROLLERS(UNILIB_ENUM_VALUE)
};

// VicCAN Data Types enum
enum class DataType : uint8_t {
    VICCAN_DATA_TYPES(UNILIB_ENUM_VALUE)
};
}  // namespace unilib
