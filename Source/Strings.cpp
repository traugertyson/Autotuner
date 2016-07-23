#include "Strings.h"

Strings::Strings()
{

}

int Strings::getStringFreq(int string)
{
	return stringArray[string-1];
}

void Strings::changeTuning(int steps)
{
	for(int i = 0; i < 6; i ++)
	{
		stringArray[i] = (int)(stringArray[i] * pow(1.059463094359,steps));
		
	}

}

void Strings::showStrings()
{
	printf("The frequencies are: ");
	for(int i = 0 ; i < 6; i++)
	{
	printf("%d, ",stringArray[i]);

	}
	printf("\n");
}
