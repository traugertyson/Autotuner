#! /bin/sh
g++ ./Source/Record.cpp ./Source/Strings.cpp ./Source/SerialPort.cpp ./Source/PitchFinder.cpp ./Source/Start.cpp -lportaudio -laubio -lasound -g -I./inc -I/usr/include/aubio -I/usr/include/ -I./Headers -w -o RunThis


