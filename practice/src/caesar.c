#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cs50.h"

#define NUM_PARA	2

int main(int argc, string argv[])
{
	int k, i;
	string input;

	if (argc != NUM_PARA)
	{
		printf("Parameter number error.\n");
		return 1;
	}
	
	k = atoi(argv[1]);
	if (k < 0)
	{
		printf("Key word should be positive.\n");
		return 1;
	}

	k %= 26;

	printf("Input string please.\n");

	input = GetString();
	if (input == NULL)
	{
		printf("Cannot get input.\n");
		return 1;
	}
	
	for (i = 0; i < strlen(input); i ++)
	{
		if (isupper(input[i]))
			fputc((input[i] - 'A' + k) % 26 + 'A', stdout);

		else if (islower(input[i]))
			fputc((input[i] - 'a' + k) % 26 + 'a', stdout);

		else fputc(input[i], stdout);
	}

	fputc('\n', stdout);
	return 0;
}
