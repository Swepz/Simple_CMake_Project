#!/bin/bash
clear
cd ..
cmake -S . -B build
cmake --build build --config Debug --target test_target
./build/test/test_target