#! /bin/bash

python3 wave.py | ../../bin/LineDraw > wave.ppm
python3 wave2.py | ../../bin/LineDraw > wave2.ppm
