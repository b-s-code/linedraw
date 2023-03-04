#! /bin/bash

g++ -Wall --std=c++17 main.cpp
./a.out | ../../bin/LineDraw > hull.ppm
