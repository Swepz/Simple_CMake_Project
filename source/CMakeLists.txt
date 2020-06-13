# Add file(s) to executable
add_executable(main main.c)
# Link shared library to main
target_link_libraries(main PRIVATE sharedLibrary)