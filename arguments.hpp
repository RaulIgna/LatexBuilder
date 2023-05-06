//
// Created by Raul on 5/6/2023.
//

#ifndef LATEXBUILDER_ARGUMENTS_HPP
#define LATEXBUILDER_ARGUMENTS_HPP

#include <string>
#include <vector>

namespace arguments
{
    extern std::vector<std::string> args;

    extern std::string name;
    extern std::string template_name;
    extern std::string path;
    extern std::string template_complete_path;
    const extern std::string directory_path; // TODO: Change this, make it linux compatible
    bool validate_arguments();
    void print_help();
}

#endif //LATEXBUILDER_ARGUMENTS_HPP
