cmake_minimum_required(VERSION 3.10)

project(Cpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Recursively gather all .cpp files under project directory (excluding build dir)
file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# (Optionally) gather header files if you want them in IDEs
file(GLOB_RECURSE PROJECT_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

# For debugging: show what sources were found
message(STATUS "Found source files:")
foreach(f IN LISTS PROJECT_SOURCES)
    message(STATUS "  ${f}")
endforeach()

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        Assignment_1/double_circular_linkedlist.cpp
        Assignment_1/Task_6_CRUD.cpp
        Assignment_1/Tugas_10.cpp
        Assignment_1/Tugas_6_CRUD.cpp
        Assignment_1/Tugas_8.1.cpp
        Assignment_1/Tugas_8.2.cpp
        Assignment_1/Tugas_8.3.cpp
        Assignment_1/Tugas_8.4.cpp
        Private/LearnCpp/0211_functions.cpp
        Private/LearnCpp/0212_functions.cpp
        Private/LearnCpp/0213_functions.cpp
        Private/LearnCpp/0221_functionReturn.cpp
        Private/LearnCpp/0222_functionReturn.cpp
        Private/LearnCpp/0223_functionReturn.cpp
        Private/LearnCpp/0224_functionReturn.cpp
        Private/LearnCpp/0231_voidFunctions.cpp
        Private/LearnCpp/0232_voidFunctions.cpp
        Private/LearnCpp/0241_functionParameters.cpp
        Private/LearnCpp/0242_functionParameters.cpp
        Private/LearnCpp/0243_functionParameters.cpp
        Private/LearnCpp/0244_functionParameters.cpp
        Private/LearnCpp/0245_functionParameters.cpp
        Private/LearnCpp/1411_OOP.cpp
        Private/LearnCpp/1412_OOP.cpp
        Private/LearnCpp/1421_classes.cpp
        Private/LearnCpp/1422_classes.cpp
        Private/TheCherno/pointers.cpp
)

# (Optional) If you want to exclude certain directories (e.g. a third-party or build folder),
# you can filter the lists or adjust GLOB_RECURSE parameters.

# Install rule (if needed)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
)
