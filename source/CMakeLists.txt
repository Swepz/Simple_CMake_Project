# Add file(s) to executable
add_executable(main_target main.c)
# Link shared library to main
target_link_libraries(main_target PRIVATE sharedLibrary)