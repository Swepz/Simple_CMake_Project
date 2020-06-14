#!/bin/bash
clear
cd ..
cmake -S . -B build
cmake --build build --config Debug --target main_target
./build/source/main_target