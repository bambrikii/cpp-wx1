cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0048 NEW)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(App1 VERSION "1.0.0")

set(THREADS_PREFER_PTHREAD_FLAG ON)


# execute_process(COMMAND $ENV{HOME}/Software/wxWidgets-3.2.1/wx-config --prefix OUTPUT_VARIABLE wxWidgets_DIR)
set(wxWidgets_DIR $ENV{HOME}/Software/wxWidgets-3.2.1)
message(STATUS "wxWidgets_DIR: ${wxWidgets_DIR}")

# execute_process(COMMAND $ENV{HOME}/Software/wxWidgets-3.2.1/wx-config --cxxflags --libs OUTPUT_VARIABLE wxWidgets_COMPILE_OPTIONS_raw)
# separate_arguments(wxWidgets_COMPILE_OPTIONS UNIX_COMMAND ${wxWidgets_COMPILE_OPTIONS_raw})
# set(wxWidgets_COMPILE_OPTIONS_raw -fdiagnostics-color=always -I/home/asd/Software/wxWidgets-3.2.1/lib/wx/include/gtk3-unicode-3.2 -I/home/asd/Software/wxWidgets-3.2.1/include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread -L/home/asd/Software/wxWidgets-3.2.1/lib -pthread -Wl,-rpath,/home/asd/Software/wxWidgets-3.2.1/lib -lwx_gtk3u_xrc-3.2 -lwx_gtk3u_html-3.2 -lwx_gtk3u_qa-3.2 -lwx_gtk3u_core-3.2 -lwx_baseu_xml-3.2 -lwx_baseu_net-3.2 -lwx_baseu-3.2)
set(wxWidgets_COMPILE_OPTIONS
-fdiagnostics-color=always
-I${wxWidgets_DIR}/lib/wx/include/gtk3-unicode-3.2
-I${wxWidgets_DIR}/include
-D_FILE_OFFSET_BITS=64
-DWXUSINGDLL
-D__WXGTK__
-pthread
-L${wxWidgets_DIR}/lib
-pthread
-Wl,-rpath,${wxWidgets_DIR}/lib
-lwx_gtk3u_xrc-3.2
-lwx_gtk3u_html-3.2
-lwx_gtk3u_qa-3.2
-lwx_gtk3u_core-3.2
-lwx_baseu_xml-3.2
-lwx_baseu_net-3.2
-lwx_baseu-3.2
)
message(STATUS "wxWidgets_COMPILE_OPTIONS: ${wxWidgets_COMPILE_OPTIONS}")

set(wxWidgets_INCLUDE_DIRS
  ${wxWidgets_DIR}/lib/wx/include/gtk3-unicode-3.2
  ${wxWidgets_DIR}/include
)
message(STATUS "wxWidgets_INCLUDE_DIRS: ${wxWidgets_INCLUDE_DIRS}")

add_compile_options(${wxWidgets_COMPILE_OPTIONS})

set(gtk_DIR /usr/include/gtk-3.0)

# add_definitions("-std=c++11")
add_executable(app1 app1.cpp)
# set_property(TARGET app1 PROPERTY COMPILE_OPTIONS -DWXUSINGDLL
# -D__WXGTK__
# -L${wxWidgets_DIR}/lib
# -Wl,-rpath,${wxWidgets_DIR}/lib)
# set_property(TARGET app1 PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")

target_include_directories(app1 PUBLIC ${wxWidgets_INCLUDE_DIRS})
target_link_directories(app1 PUBLIC ${wxWidgets_DIR}/lib)
target_link_directories(app1 PUBLIC /usr/lib/x86_64-linux-gnu)
# link_directories(/usr/lib/x86_64-linux-gnu ${wxWidgets_DIR}/lib)

# link_directories(${gtk_DIR})
# link_directories(${wxWidgets_DIR}/lib)

# target_link_libraries(app1 ${wxWidgets_DIR}/lib/)


add_executable(app2 app2.cpp)
target_include_directories(app2 PUBLIC ${wxWidgets_INCLUDE_DIRS})
target_link_directories(app2 PUBLIC ${wxWidgets_DIR}/lib)
target_link_directories(app2 PUBLIC /usr/lib/x86_64-linux-gnu)
