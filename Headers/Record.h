#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include <complex.h>
#include <fftw3.h>
#include <aubio.h>
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <string.h>
#include <sstream>
#include <stdexcept>
#include <termios.h> /* POSIX terminal control definitions */
#include <sys/ioctl.h>
#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (4096)
#define NUM_CHANNELS (2)

class Record
{
	public:
		/** Default constructor*/
		Record();

		/**
			Initializes the object 
			@return The error status
		*/
		PaError initialize();

		
		/**
			Starts the stream
			@return the error status
		*/
		PaError start();
		
		/**
			Ends the stream
			@return the error status
		*/
		PaError end();
		
		/**
			Records the data from the mic into the parameter
			@param in - holds the values from the mic
			@return the error status
		*/
		PaError recordData(float *in);

	private:
		PaStreamParameters inputParameters; /**<Holds the data that is needed to setup the mic */
		PaStream *stream; /**<Holds the address of the opened stream */
		PaError err;		/**<Holds the error statuses */

};

#endif

