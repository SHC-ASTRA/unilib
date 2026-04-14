#include <pybind11/pybind11.h>

#include "unilib/can_defs.hpp"

namespace py = pybind11;

// Helper macro to add enum values with docstrings
#define PYBIND_ENUM_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::MessageType::NAME, DOC)
#define PYBIND_MCU_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::Microcontroller::NAME, DOC)
#define PYBIND_DTYPE_VALUE(NAME, VALUE, DOC) .value(#NAME, unilib::DataType::NAME, DOC)

PYBIND11_MODULE(unilib, m, py::mod_gil_not_used()) {
    m.doc() = "ASTRA unilib - shared definitions for VicCAN protocol";

    // MessageType enum
    py::enum_<unilib::MessageType>(m, "MessageType", "VicCAN message type identifiers")
        VICCAN_MESSAGE_TYPES(PYBIND_ENUM_VALUE)
            .export_values();

    // Microcontroller enum
    py::enum_<unilib::Microcontroller>(m, "Microcontroller", "VicCAN microcontroller identifiers")
        VICCAN_MICROCONTROLLERS(PYBIND_MCU_VALUE)
            .export_values();

    // DataType enum
    py::enum_<unilib::DataType>(m, "DataType", "VicCAN data payload types")
        VICCAN_DATA_TYPES(PYBIND_DTYPE_VALUE)
            .export_values();
}
