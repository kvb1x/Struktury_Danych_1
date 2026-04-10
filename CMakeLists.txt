cmake_minimum_required(VERSION 3.10)

project(Struktury_Danych_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(StrukturyDanych ${SOURCES})

target_include_directories(StrukturyDanych PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(StrukturyDanych PRIVATE -Wall -Wextra -Wpedantic)

