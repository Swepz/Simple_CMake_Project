cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)
set(CMAKE_C_STANDARD 99)
# Split project into seperate cmake files
add_subdirectory(source)

# Add file(s) to a shared library
add_library(sharedLibrary STATIC 
    include/main.h
)

find_library(MATH_LIBRARY m)
target_link_libraries(sharedLibrary PUBLIC ${MATH_LIBRARY})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)
target_link_libraries(sharedLibrary PUBLIC -pthread)

# Add directory "include" to target
target_include_directories(sharedLibrary PUBLIC include)
# Set linker langugage to C
SET_TARGET_PROPERTIES(sharedLibrary PROPERTIES LINKER_LANGUAGE C)