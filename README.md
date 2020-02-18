# Instructions

## Install
sudo apt-get install build-essential gnome-devel -y
### Verify installed
- sudo apt-get install libgtk-3-dev -y
- sudo apt-get install libcairo2-dev -y

## How to run

### Using clion
1. New CMake Project from sources
2. Find directory
3. OPEN EXISTING PROJECT
4. Select server first and run, then in the dropdown menu select client and run again.

### Using terminal
1. Open two terminals
2. Go to project bin folder on both terminals
3. - Running server terminal 1: ./server.sh
   - Running client terminal 2: ./client.sh

If files are not executable, you need to use command: chmod +x server.sh client.sh

## Project file structure
Project

    - bin
        - client.sh
        - server.sh

    - source
        - client.c
        - server.c

    - include
       - Dump remaning .c and .h files
