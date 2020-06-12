# Add file(s) to executable
add_executable(main main.c)
# Link math and pthread library to main
target_link_libraries(main PUBLIC m rt)
# Link shared library from directory "include" with main
target_link_libraries(main PUBLIC sharedLibrary)

# Add file(s) to executable
add_executable(test test.c)
# Link math and pthread library to test
target_link_libraries(test PUBLIC m rt)
# Link shared library from directory "include" with test
target_link_libraries(test PUBLIC sharedLibrary)