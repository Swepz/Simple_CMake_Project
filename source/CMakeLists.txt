# Add file(s) to executable
add_executable(main 
    main.c
)
# Link shared library to main
target_link_libraries(main PUBLIC sharedLibrary)

# Add file(s) to executable
add_executable(test 
    test.c
)
# Link shared library to test
target_link_libraries(test PUBLIC sharedLibrary)