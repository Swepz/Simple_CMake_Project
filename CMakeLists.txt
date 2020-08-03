cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)

# Create HEADER-ONLY shared library
add_library(sharedLibrary INTERFACE)
# Add directory "include" to target library
target_include_directories(sharedLibrary INTERFACE library)
# Target link math, pthread and GTK to shared library
target_link_libraries(sharedLibrary INTERFACE rt m)

add_executable(main source/main.c)
add_executable(test source/main.c)
# Link shared library to main
target_link_libraries(main PUBLIC sharedLibrary)
