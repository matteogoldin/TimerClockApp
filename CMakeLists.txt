cmake_minimum_required(VERSION 3.12)
project(TimerClockApp)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES App.cpp App.h Frame.cpp Frame.h CFrame.cpp CFrame.h SWFrame.cpp SWFrame.h CTimer.cpp CTimer.h
        SWPauseFrame.cpp SWPauseFrame.h SWTimer.cpp SWTimer.h SWContinueFrame.cpp SWContinueFrame.h TFrame.cpp TFrame.h
        TPauseFrame.cpp TPauseFrame.h TTimer.cpp TTimer.h)

add_executable(TimerClockApp ${SOURCE_FILES})
add_subdirectory(test)
add_library(core ${SOURCE_FILES})

target_link_libraries(TimerClockApp ${wxWidgets_LIBRARIES} core)

