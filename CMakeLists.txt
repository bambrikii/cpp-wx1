cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0048 NEW)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(App2 VERSION "1.0.0")

execute_process(COMMAND $ENV{HOME}/Software/wxWidgets-3.2.1/wx-config --cxxflags --libs OUTPUT_VARIABLE wxWidgets_COMPILE_OPTIONS_raw)
execute_process(COMMAND $ENV{HOME}/Software/wxWidgets-3.2.1/wx-config --prefix OUTPUT_VARIABLE wxWidgets_DIR)
separate_arguments(wxWidgets_COMPILE_OPTIONS UNIX_COMMAND ${wxWidgets_COMPILE_OPTIONS_raw})
message(STATUS "wxWidgets_COMPILE_OPTIONS: ${wxWidgets_COMPILE_OPTIONS}")
message(STATUS "wxWidgets_DIR: ${wxWidgets_DIR}")

add_compile_options(${wxWidgets_COMPILE_OPTIONS})

add_definitions("-std=c++11")
add_executable(app1 app1.cpp)

set(gtk_DIR /usr/include/gtk-3.0)

link_directories(/usr/lib/x86_64-linux-gnu)
link_directories(${gtk_DIR})
link_directories(${wxWidgets_DIR}/lib)

target_include_directories(app1 PRIVATE ${wxWidgets_INCLUDE_DIRS})
