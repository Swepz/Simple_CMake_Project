cmake_minimum_required(VERSION 3.00)
project(projectName C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lm")
include_directories(include)
include_directories(source)

add_executable(main
        source/main.c
        include/main.h
        )
add_executable(test
        test/test.c
        source/main.c
        include/main.h
        )

# Target link lib to executable
target_link_libraries(main rt m)
target_link_libraries(test rt m)
