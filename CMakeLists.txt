cmake_minimum_required(VERSION 3.12)
project(TimerClockApp)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES App.cpp Frame.cpp CFrame.cpp SWFrame.cpp CTimer.cpp SWPauseFrame.cpp SWTimer.cpp
        SWContinueFrame.cpp TFrame.cpp TPauseFrame.cpp TContinueFrame.cpp TObserver.cpp Functions.cpp)

add_executable(TimerClockApp ${SOURCE_FILES})
add_subdirectory(test)
add_library(core ${SOURCE_FILES})

target_link_libraries(TimerClockApp ${wxWidgets_LIBRARIES} core)

