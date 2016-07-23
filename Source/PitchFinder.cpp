#include "PitchFinder.h"


PitchFinder::PitchFinder(const int SIZE,const int SR)
{
	this->SIZE = SIZE;
	in = new_fvec(SIZE);
	o = new_aubio_pitch("default",SIZE,SIZE/4,SR);
	pitch = new_fvec(SIZE);
}

int PitchFinder::getPitch(float *signal)
{
	for(int i = 0; i <SIZE; i++)
	{
		in->data[i] = (float)signal[i];

	}
	aubio_pitch_do(o,in,pitch);
	freq = fvec_get_sample(pitch,0);
	return freq;


}

int PitchFinder::getDifference(int pitch, int desiredFreq)
{
	return desiredFreq - pitch;
}

int PitchFinder::getWhichWay(int difference)
{
	if(difference > 0)
	{
		return 1;
	}
	else if(difference < 0)
	{
		return 2;
	}
	else
	{
		return 0;
	}

}
