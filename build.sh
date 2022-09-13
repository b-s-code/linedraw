#! /bin/bash

g++ -Wall -std=c++17 \
./src/main.cpp \
./src/coordrships.cpp \
./src/PPMImage.cpp \
./src/EdgeParser.cpp \
-o ./bin/LineDraw
