# Simple C project structure example using CMake

Note that this project does not require the user to smash commands in terminal.
If the user have a IDE that supports CMake, both executables(main,test) should automatically be seperated into two instances by default.

Required packages are CMake(version > 3.0)

Installation:

Ubuntu

> sudo apt install cmake

Arch Linux

> sudo pacman -S cmake

Other: [Select a distro that floats your boat](https://cmake.org/download/)

## Project structure

```bash
├── bin
│   ├── main.sh
│   └── test.sh
├── CMakeLists.txt
├── include
│   └── main.h
├── README.md
├── source
│   ├── CMakeLists.txt
│   └── main.c
└── test
    ├── CMakeLists.txt
    └── test.c
```
#### Note: The directory "test" is optional.


### How to build, compile & run

1. Locate shell scripts in directory bin/

```bash
├── bin
│   ├── main.sh 
│   └── test.sh

```

2. Execute

> ./main.sh

OR

> ./test.sh


#### Note that the following *.sh files might not be executable

- If not executable then

    > chmod +x insertFileName.sh

*Edit the shell scripts to prefered file to execute*

```bash
#!/bin/bash 
# main.sh
clear
cd ..
target=main_target <-------------------- Change here
cmake -S . -B build
cmake --build build --config Debug --target $target
./build/source/$target
```
The file binary file "main_target" comes from source/CMakeLists.txt

> "add_executable(**main_target** main.c)"


### Add new source files

1. Add new source files to "source/" 

```bash
├── source
│   ├── CMakeLists.txt
│   └── main.c
```

> cd source/

> touch linked_list.c

```bash
└── source
    ├── CMakeLists.txt
    ├── linked_list.c
    ├── main.c
```

### Add library files

HEADER-ONLY directory for library files are located in "include"

```bash
├── include
│   └── main.h
```

1. Create new file

> cd include/

> touch linked_list.h

```bash
├── include
│   ├── linked_list.h
│   └── main.h
```


#### Note: Math and Pthread has been linked to sharedLibrary by default

> target_link_libraries(sharedLibrary PUBLIC m rt)

flag "rt" is used by pthread.h

flag "m" is used by math.h
