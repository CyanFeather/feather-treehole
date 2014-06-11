#include <stdio.h>
#include "cs50.h"

int main(void)
{
	float tempC, tempF;
	printf("Input temperature(F): ");
	tempF = GetFloat();
	
	tempC = (float) 5 / 9 * (tempF - 32);
	printf("Temperature(C): %.2f\n", tempC);
	return 0;
}
