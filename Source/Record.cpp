#include "Record.h"



Record::Record()
{


}

PaError Record::initialize()
{
PaError err = paNoError;
	err = Pa_Initialize();
	if(err == paNoError)
	{
		inputParameters.device = Pa_GetDefaultInputDevice();
		if(inputParameters.device == paNoDevice)
		{
			err = paInternalError;
		}
		else
		{
			inputParameters.channelCount = 1;
			inputParameters.sampleFormat = paFloat32;
			inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
			inputParameters.hostApiSpecificStreamInfo = NULL;

		}
	}
	return err;
}

PaError Record::start()
{
	PaError err = paNoError;
	err = Pa_OpenStream(&stream,&inputParameters,NULL,SAMPLE_RATE,FRAMES_PER_BUFFER,paClipOff,NULL,NULL);
	if(err == paNoError)
	{
		err = Pa_StartStream(stream);
	}
	return err;
}

PaError Record::end()
{
	PaError err = paNoError;
	err  = Pa_CloseStream(stream);
	return err;

}

PaError Record::recordData(float *in)
{
	PaError err = paNoError;
	err = Pa_ReadStream(stream,&in[0], FRAMES_PER_BUFFER);
	return err;}
