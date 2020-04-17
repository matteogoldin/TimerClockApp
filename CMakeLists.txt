cmake_minimum_required(VERSION 3.12)
project(TimerClockApp)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(TimerClockApp App.cpp)

target_link_libraries(TimerClockApp ${wxWidgets_LIBRARIES})