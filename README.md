This project will find the current tuning of a guitar string and determine if it is in tune or not. The guitar should be plugged into the microphone jack of the computer in use. Tested only on Ubuntu 14.04 and 16.04.
This also can be used with an arduino (or similar device) to automatically tune the guitar. The setup tested with is an arduino listening on the serial port /dev/ttyACM0. This program sends a 1 if the string is flat and a 2 if the string is sharp. 

To install the needed dependencies, run prereqs.sh.
