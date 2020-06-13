cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)
set(CMAKE_C_STANDARD 99)
# Split project into seperate cmake files
add_subdirectory(source)

# Create HEADER-ONLY shared library
add_library(sharedLibrary INTERFACE)
# Add directory "include" to target library
target_include_directories(sharedLibrary INTERFACE include)
# Target link math and pthread to shared library
target_link_libraries(sharedLibrary INTERFACE rt m)

install_targets(source sharedLibrary)