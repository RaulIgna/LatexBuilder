//
// Created by Raul on 5/6/2023.
//

#include <fstream>
#include <filesystem>
#include "parse.hpp"
#include "arguments.hpp"
#include "Dependencies/json/json.hpp"
#include "print.hpp"
#include "Dependencies/fmt/core.h"

using json = nlohmann::json;
namespace fs = std::filesystem;

namespace parse
{
    void parse_file()
    {
        std::string data = load_json(arguments::template_complete_path);

        assert(!data.empty());
        std::string final_name = fmt::format("{}/{}.tex",arguments::path,arguments::name);
        std::fstream out(final_name,std::fstream::out);
        out.write(data.c_str(),data.size());
        out.close();
        if(fs::exists(final_name))
            print::PrintSuccess("Created file successfully!");
        else
            print::PrintError("File was not created!");
    }

    std::string load_json(const std::string& in)
    {
        std::string ret = "";
        std::ifstream file_in(in);
        json json_input = json::parse(file_in);

        ret = fmt::format("\\documentclass[{}]{{{}}}\n", json_input["documentclass"][0],json_input["documentclass"][1]);

        for(const auto& lib : json_input["packages"])
        {
            ret += fmt::format("\\usepackage{{{}}}\n",lib);
        }
        ret += fmt::format(
                "\\title{{{}}}\n"\
                "\\date{{{}}}\n"\
                "\\author{{{}}}\n"\
                "\\begin{{{}}}\n"\
                "\\maketitle\n\n"\
                "\\end{{{}}}\n",
                json_input["title"], "",json_input["author"],"document","document"
                );
        return ret;
    }
}