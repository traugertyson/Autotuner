#! /bin/sh
g++ Record.cpp Strings.cpp SerialPort.cpp PitchFinder.cpp Start.cpp -lportaudio -laubio -lasound -g -I./inc -I/usr/include/aubio -I/usr/include/ -I../Headers -w


