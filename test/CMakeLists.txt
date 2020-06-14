# Add file(s) to executable
add_executable(test_target test.c)
# Link shared library to test
target_link_libraries(test_target PRIVATE sharedLibrary)
target_link_libraries(test_target PRIVATE sourceFiles)