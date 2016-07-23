#ifndef STRINGS_H
#define STRINGS_H
#include <cstdio>
#include <cmath>
class Strings
{
	public:
		/** Default Constructor */
		Strings();

		/**
			Returns the ideal frequency, in hertz,  of the string
			@param string - the string you want to find the frequency of
			@return the frequency of the string
		*/
		int	getStringFreq(int string);

		/**
			Changes the tuning that you want the guitar to be in (e.g half step down, etc).
			@param steps - how many steps you want the tuning to change from standard
		*/
		void changeTuning(int steps);

		/**
			Prints out the ideal frequencies of the strings that the tuner will try and tune to
		*/
		void showStrings();
	
	private:
		int stringArray[6] =  {82,110,147,196,247,329}; /**<The ideal frequencies of the strings that the tuner will try and tune to. index [0] is the low E, [1] is the a, etc */

};

#endif
