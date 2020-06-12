cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)
set(CMAKE_C_STANDARD 99)
# Split project into seperate cmake files
add_subdirectory(source)

# Add file(s) to a shared library
add_library(sharedLibrary STATIC 
    include/main.h
)
# Add directory "include" to target
target_include_directories(sharedLibrary PUBLIC include)
# Set linker langugage to C
SET_TARGET_PROPERTIES(sharedLibrary PROPERTIES LINKER_LANGUAGE C)