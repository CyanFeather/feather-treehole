#include <stdio.h>
#include <math.h>
#include "cs50.h"

int main(void)
{
	float dollar;
	int penny, counter = 0;
	
	do
	{
		printf("O hai!\t How much change is owed?\n");
		dollar = GetFloat();
	}
	while (dollar < 0);

	penny = (int) round (dollar * 100);
	printf("We should return %d pennys.\n", penny);

	while (penny >= 25)
	{
		penny -= 25;
		counter ++;
	}

	while (penny >= 10)
	{
		penny -= 10;
		counter ++;
	}

	while (penny >= 5)
	{
		penny -= 5;
		counter ++;
	}

	while (penny != 0)
	{
		penny --;
		counter ++;
	}

	printf("Total %d coins.\n", counter);	
	return 0;
}
