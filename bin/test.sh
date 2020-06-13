#!/bin/bash
clear
cd ..
cmake -S . -B build
cmake --build build --config Debug --target test -- -j 6
./build/test/test