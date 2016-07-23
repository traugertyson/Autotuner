#ifndef TUNER_H
#define SERIALPORT_H

#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <cstdio>

class SerialPort
{
	public:

		/**
			Constructor
			@param filename - the directory of the serialport
		
		*/
		SerialPort(char *filename);

		/**
			Initializes the Serial port
		*/
		void initialize();			

		/**
			Sends an integer value to the port
			@param num - the number you want to send to the port
			@return if the write worked correctly
		*/
		bool sendInt(int num);

	private:

		int fd;	/**<The file descriptor*/
		char *filename;	/**<The directory of the serial port*/
};
#endif
