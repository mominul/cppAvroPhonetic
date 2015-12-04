# From https://github.com/nlohmann/json
cmake_minimum_required(VERSION 2.8)

project(cppAvroPhonetic)

include_directories(
    src test
)

if(MSVC)
    set(CMAKE_CXX_FLAGS
        "/EHsc"
    )

    STRING(REPLACE "/O2" "/Od" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})

    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
else(MSVC)
    set(CMAKE_CXX_FLAGS
        "-std=c++11"
    )
endif(MSVC)

add_executable(avro_test
    src/avrophonetic.hpp test/test.cpp
)
