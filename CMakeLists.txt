cmake_minimum_required(VERSION 3.00)
project(Lab3 C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lpthread -lrt")
include_directories(include)
include_directories(source)
# FIND ALL PACKAGES FROM PKGCONFIG
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

file(GLOB myinclude
    "include/*.c"
    "include/*.h")

# Make server.c executable and name it server
add_executable(server source/server.c ${myinclude})
# Include GTK lib
target_include_directories(server PUBLIC ${GTK_INCLUDE_DIRS})
# Target link lib to executable
target_link_libraries(server rt m ${GTK_LIBRARIES})

# Make client.c executable and name it client
add_executable(client source/client.c ${myinclude})
# Include GTK lib
target_include_directories(client PUBLIC ${GTK_INCLUDE_DIRS})
# Target link lib to executable
target_link_libraries(client rt)
