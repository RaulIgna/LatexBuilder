cmake_minimum_required(VERSION 3.25)
project(LatexBuilder)

set(CMAKE_CXX_STANDARD 23)

add_executable(LatexBuilder main.cpp arguments.cpp arguments.hpp parse.cpp parse.hpp Dependencies/json/json.hpp
        Dependencies/fmt/args.h Dependencies/fmt/chrono.h Dependencies/fmt/color.h Dependencies/fmt/compile.h
        Dependencies/fmt/core.h Dependencies/fmt/format.h Dependencies/fmt/format-inl.h Dependencies/fmt/os.h
        Dependencies/fmt/ostream.h Dependencies/fmt/printf.h Dependencies/fmt/ranges.h Dependencies/fmt/std.h Dependencies/fmt/xchar.h print.cpp print.hpp)
