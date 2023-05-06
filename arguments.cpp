//
// Created by Raul on 5/6/2023.
//
#include <iostream>
#include <filesystem>
#include "print.hpp"
#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#include "Dependencies/fmt/core.h"
#include "arguments.hpp"

namespace fs = std::filesystem;

namespace arguments
{
    std::vector<std::string> args;
    std::string name;
    std::string template_name;
    std::string path;
    std::string template_complete_path;

    const std::string directory_path = "C:/Users/Public/Documents/LatexBuilder";
    void print_help()
    {
        fmt::print(
                "This is a CLI tool to create .tex files using user-defined templates\n"\
                "To use the program run it from a terminal using the following arguments\n"\
                "<template> <name> <location>\n"\
                "<template> is used for the template name, WITHOUT .json\n"\
                "<name> is the name of the file to be created, WITHOUT .tex\n"\
                "<location> is the directory where the file will be saved\n"
                );
    }

    bool validate_arguments()
    {
        if(!fs::exists(directory_path))
        {
            print::PrintWarning(fmt::format("Creating a folder for the templates in {}\n"\
                    "This should only run once\n"\
                    "Save or create some templates in {} and re-run the program\n",
                   directory_path.c_str(),directory_path.c_str()));
            if(!fs::create_directory(directory_path))
            {
                print::PrintError("Failed to create directory");
            }
            return false;
        }



        // Verify if the user command if --help
        if(std::any_of(args.begin(), args.end(), [](const std::string& arg) -> bool {
            return arg == "--help";
        }))
        {
            print_help();
            return false;
        }

        if(args.size() != 3){
            print::PrintError("Invalid number of arguments! Use --help for help!");
            return false;
        }

        template_name = args[0];
        name = args[1];
        path = args[2];

        template_complete_path = directory_path + "/" + template_name + ".json";
        if(!fs::exists(template_complete_path))
        {
            print::PrintError("Error! The template does not exist!");
            return false;
        }

        return true;
    }
}