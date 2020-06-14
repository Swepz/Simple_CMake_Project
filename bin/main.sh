#!/bin/bash
clear
cd ..
target=main_target
cmake -S . -B build
cmake --build build --config Debug --target $target
./build/source/$target
