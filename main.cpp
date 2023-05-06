#include <iostream>
#include "arguments.hpp"
#include "parse.hpp"

int main(int argc, char** argv) {

    // Save the useful arguments to a std::vector<std::string>
    std::copy(argv + 1, argv + argc, std::back_inserter(arguments::args));

    // Check for arguments and store the information
    if(!arguments::validate_arguments())
        return 0;

    // Parse and create the file
    parse::parse_file();

    return 0;
}
