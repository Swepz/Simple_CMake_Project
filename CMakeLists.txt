cmake_minimum_required(VERSION 3.00)
project(exampleProjectName LANGUAGES C)
# Split project into seperate cmake files
add_subdirectory(source)

if(EXISTS "${PROJECT_SOURCE_DIR}/test")
	add_subdirectory(test)
	add_library(sourceFiles INTERFACE)
	# Add directory "source" to target
	target_include_directories(sourceFiles INTERFACE source)
endif()

# Create HEADER-ONLY shared library
add_library(sharedLibrary INTERFACE)
# Add directory "include" to target library
target_include_directories(sharedLibrary INTERFACE include)
# Target link math and pthread to shared library
target_link_libraries(sharedLibrary INTERFACE rt m)