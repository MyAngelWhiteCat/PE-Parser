cmake_minimum_required(VERSION 3.11)

project(PEParser CXX)

set(CMAKE_CXX_STANDARD 20)


find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(Logger 
    src/Logger/logger.h
    src/Logger/logger.cpp
)

target_link_libraries(Logger PUBLIC 
    spdlog::spdlog
)

add_library(Parser
    src/Parser/pe_parser.h
    src/Parser/pe_parser.cpp 
)

add_executable(PEParser
    src/main.cpp
)

target_link_libraries(PEParser
    Logger
    Parser
)
