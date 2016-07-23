This project will find the current tuning of a guitar string and determine if it is in tune or not. The guitar should be plugged into the microphone jack of the computer in use.
This also can be used with an arduino (or similar device) to automatically tune the guitar. The setup I have tested with is an arduino listening on the serial port /dev/ttyACM0. This program sends a 1 if the string is flat and a 2 if the string is sharp. 

The dependencys needed are portaudio, lfftw3, and the aubio library.
To compile, use this: g++ Record.cpp Strings.cpp SerialPort.cpp PitchFinder.cpp Start.cpp -lportaudio -lfftw3 -laubio -lasound -g -I./inc -I/usr/include/aubio -I/usr/include/ -I../Headers -w

