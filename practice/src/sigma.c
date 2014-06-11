#include <stdio.h>
#include "cs50.h"

int sigma(int m);

int main(void)
{
	// ask user for a positive int
	int input;
	do
	{
		printf("Positive integer please: ");
		input = GetInt();
	}
	while (input < 1);

	printf("%d\n", sigma(input));
	return 0;
}

int sigma(int m)
{
	// CAUTION: Recursion may cause segmentation fault

	// avoid risk of infinite loop
	if (m < 1)
		return 0;

	// recursive case
	else
		return (m + sigma(m - 1));
}
