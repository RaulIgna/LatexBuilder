//
// Created by Raul on 5/6/2023.
//

#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif

#include "print.hpp"
#include "Dependencies/fmt/core.h"
#include "Dependencies/fmt/color.h"

namespace print
{
    void PrintError(const std::string &message) {
        fmt::print(fmt::fg(fmt::color::red), "Error: {}\n", message);
    }

    void PrintWarning(const std::string &message) {
        fmt::print(fmt::fg(fmt::color::yellow), "Warning: {}\n", message);
    }

    void PrintSuccess(const std::string &message) {
        fmt::print(fmt::fg(fmt::color::green), "Success: {}\n", message);
    }
}