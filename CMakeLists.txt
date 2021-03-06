cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sorting-algorithms)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/_Display/Display.cpp src/_Display/Display.h src/ShakerSort/ShakerDisplay.cpp src/ShakerSort/ShakerDisplay.h src/utility.cpp src/utility.h src/BubbleSort/BubbleDisplay.cpp src/BubbleSort/BubbleDisplay.h src/InsertionSort/InsertionDisplay.cpp src/InsertionSort/InsertionDisplay.h src/SelectionSort/SelectionDisplay.cpp src/SelectionSort/SelectionDisplay.h src/test.cpp src/MergeSort/MergeDisplay.cpp src/MergeSort/MergeDisplay.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:\\_programs\\sfml\\SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()