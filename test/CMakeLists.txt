# Add file(s) to executable
add_executable(test test.c)
# Link shared library to test
target_link_libraries(test PRIVATE sharedLibrary)
target_link_libraries(test PRIVATE sourceFiles)