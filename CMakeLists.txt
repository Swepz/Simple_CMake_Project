cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)

# Find math and pthread library
find_library(MATH m REQUIRED)
find_library(PTHREAD rt REQUIRED)

# Create HEADER-ONLY shared library
add_library(sharedLibrary INTERFACE)
# Add directory "include" to target library
target_include_directories(sharedLibrary INTERFACE library)
# Target link math and pthread to shared library
target_link_libraries(sharedLibrary INTERFACE ${MATH} ${PTHREAD})

# Create a binary executable
add_executable(main source/main.c)
# Link shared library to main
target_link_libraries(main PRIVATE sharedLibrary)
