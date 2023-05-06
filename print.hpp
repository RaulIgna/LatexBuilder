//
// Created by Raul on 5/6/2023.
//

#ifndef LATEXBUILDER_PRINT_HPP
#define LATEXBUILDER_PRINT_HPP

#include <string>

namespace print
{
    extern void PrintError(const std::string& message);
    extern void PrintWarning(const std::string& message);
    extern void PrintSuccess(const std::string& message);
}

#endif //LATEXBUILDER_PRINT_HPP
