#!/bin/bash
clear
target=$1
cmake -S . -B build
cmake --build build --config Debug --target $target
./build/$target
