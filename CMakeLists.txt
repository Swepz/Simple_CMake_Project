cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)

# Find math and pthread library
find_library(MATH m REQUIRED)

# Create HEADER-ONLY library
add_library(HEADER-ONLY INTERFACE)
# Add project lib
add_library(PROJECTLIB INTERFACE)
# Add directory "include/" to target library
target_include_directories(HEADER-ONLY INTERFACE ${CMAKE_SOURCE_DIR}/include)
# Add directory "lib/" to target library
target_include_directories(PROJECTLIB INTERFACE ${CMAKE_SOURCE_DIR}/lib)

# Target link math to HEADER-ONLY
target_link_libraries(HEADER-ONLY INTERFACE ${MATH})
# Target link HEADER-ONLY to PROJECTLIB
target_link_libraries(HEADER-ONLY INTERFACE PROJECTLIB)

# Create a binary executable
add_executable(main main.c)
# Link shared library to main
target_link_libraries(main PRIVATE HEADER-ONLY)
