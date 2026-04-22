/**
 * @file can_defs.hpp
 * @author Riley (rjm0037@uah.edu)
 * @author David (ds0196@uah.edu)
 * @brief CAN message definitions for VicCAN in Python
 *
 */

// Only usable from rover-ros2
#ifndef ARDUINO

#    include <pybind11/pybind11.h>

#    include "unilib/can_defs.hpp"

namespace py = pybind11;

// Helper macro to add enum values with docstrings
#    define PYBIND_ENUM_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::CanCmdId::NAME, DOC)
#    define PYBIND_MCU_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::CanMcuId::NAME, DOC)
#    define PYBIND_DTYPE_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::CanDataType::NAME, DOC)

PYBIND11_MODULE(unilib, m, py::mod_gil_not_used()) {
    m.doc() = "ASTRA unilib - shared definitions for VicCAN protocol";

    // CanCmdId enum
    py::enum_<unilib::CanCmdId>(m, "CanCmdId", "VicCAN command identifiers")
        VICCAN_COMMANDS(PYBIND_ENUM_VALUE)
            .export_values();

    // CanMcuId enum
    py::enum_<unilib::CanMcuId>(m, "CanMcuId", "VicCAN microcontroller identifiers")
        VICCAN_MICROCONTROLLERS(PYBIND_MCU_VALUE)
            .export_values();

    // CanDataType enum
    py::enum_<unilib::CanDataType>(m, "CanDataType", "VicCAN data payload types")
        VICCAN_DATA_TYPES(PYBIND_DTYPE_VALUE)
            .export_values();
}

#endif
