#!/bin/bash
clear
cd ..
target=test_target
cmake -S . -B build
cmake --build build --config Debug --target $target
./build/test/$target
