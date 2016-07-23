#ifndef PITCHFINDER_H
#define PITCHFINDER_H
#include <aubio.h>
#include <cstdio>

class PitchFinder
{
	public:
		/**
		The constructor. It takes as parameters FRAMES_PER_BUFFER and SAMPLE_RATE
		@param SIZE FRAMES_PER_BUFFER
		@param SR SAMPLE_RATE
		*/
		
		PitchFinder(const int SIZE,const int SR);
		
		/**
			Returns the pitch in hertz of a signal that is passed as a parameter
			@param signal - the raw signal from the mic
			@return the frequency of the signal
		*/
		int getPitch(float *signal);
		/**
			Returns the difference between the disired frequency and the actual pitch
			@param pitch - the actual pitch
			@param desiredFreq - the pitch you want it to be
			@return desiredFreq minus the  pitch
		*/
		int getDifference(int pitch, int desiredFreq);

		/**
			Returns the value that will be fed to the serial port in order to turn the motor the right way.
			@param difference - the value given by getDifference
			@return the value to be fed to the serial port
		*/
		int getWhichWay(int difference);

	private:
		int SIZE;	/**<The Size of the buffer*/
		
		aubio_pitch_t *o;/**<The aubio object that will perform the sampling*/
		fvec_t *pitch;	/**<Holds the pitch found by the signal sampling*/
		fvec_t *in;		/**<The instance varible that holds the raw signal*/
		float freq;		/**<The float conversion of the found frequency*/

};

#endif
