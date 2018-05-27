# From https://github.com/nlohmann/json
cmake_minimum_required(VERSION 2.8)

project(cppAvroPhonetic)

## Set Compiler Standard
set(CMAKE_CXX_STANDARD 11)

include_directories(
    src test
)

add_executable(avro_test
    src/avrophonetic.hpp test/test.cpp
)
