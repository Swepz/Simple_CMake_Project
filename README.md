# Simple C project structure example using CMake

Note that this project does not require the user to smash commands in terminal.
If the user have a IDE that supports CMake, both executables(main,test) should automatically be seperated into two instances by default.

Required packages are CMake(version > 3.1)

Installation:

Ubuntu

> sudo apt install cmake 

Arch Linux

> sudo pacman -S cmake 


Other: [Select a distro that floats your boat](https://cmake.org/download/)


### How to: Define project name
1. Locate CMakeLists.txt in root directory

```bash
CMakeLists.txt <----------------- Change here
library/
build/
run.sh
README.md
source/
```
2. Change "exampleProjectName" to a suitable name

Example:

> project(**exampleProjectName** LANGUAGES C)

exampleProjectName -> realProjectName


> project(**realProjectName** LANGUAGES C)


### How to: Build, compile & run

> sh run.sh main

#### Note that the run.sh file might not be executable

- If not executable then

    > chmod +x run.sh

*Edit shell script for custom target to be launched*

The file binary file "main" comes from source/CMakeLists.txt

> "add_executable(**main** main.c)"

#### Note: Math and Pthread has been linked to sharedLibrary by default
> target_link_libraries(sharedLibrary INTERFACE ${MATH} ${PTHREAD})
