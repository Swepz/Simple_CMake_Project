#!/bin/bash
clear
cd ..
cmake -S . -B build
cmake --build build --config Debug --target test
./build/test/test