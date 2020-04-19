cmake_minimum_required(VERSION 3.12)
project(TimerClock)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(TimerClock main.cpp)

target_link_libraries(TimerClock ${wxWidgets_LIBRARIES})
