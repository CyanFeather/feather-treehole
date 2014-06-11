#include <stdio.h>
#include "cs50.h"

int main()
{
	int height, index, counter;
	do
	{
		printf("Height: ");
		height = GetInt();
	}
	while ((height > 23) || (height < 1));

	for (index = 1; index <= height; index ++)
	{
		for (counter = 0; counter < (height - index); counter ++)
			printf(" ");
		for (counter = 0; counter < (index + 1); counter ++)
			printf("#");
		printf("\n");
	}
	return 0;
}
