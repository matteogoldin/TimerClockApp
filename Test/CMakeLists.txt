project(test)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES runAllTests.cpp TObserverTest.cpp FunctionsTest.cpp) #aggiungere i test via via che vengono creati
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core ${wxWidgets_LIBRARIES})
