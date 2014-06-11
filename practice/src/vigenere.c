#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cs50.h"

#define NUM_PARA	2

int main(int argc, string argv[])
{
	int i, indexKeyword = 0;
	int numKeyword;
	int* keyword;
	string input;

	if (argc != NUM_PARA)
	{
		printf("Parameter number error.\n");
		return 1;
	}

	numKeyword = strlen(argv[1]);
	keyword = (int *) malloc(numKeyword * sizeof(int));
	if (keyword == NULL)
	{
		printf("malloc error.\n");
		return 1;
	}

	for (i = 0; i < numKeyword; i ++)
		if (isalpha(argv[1][i]))
		{
			keyword[i] = toupper(argv[1][i]);
			keyword[i] -= 'A';
		}
		else
		{
			printf("Key word should not contain non-alphabetical character.\n");
			return 1;
		}

	// Print key word
	/*
	for (i = 0; i < numKeyword; i ++)
		printf("%d ", keyword[i]);
	printf("\n");
	*/

	input = GetString();
	if (input == NULL)
	{
		printf("Cannot get input.\n");
		return 1;
	}
	
	for (i = 0; i < strlen(input); i ++)
	{
		if (isalpha(input[i]))
		{
			if (isupper(input[i]))
				fputc((input[i] - 'A' + keyword[indexKeyword]) % 26 + 'A', stdout);
			else
				fputc((input[i] - 'a' + keyword[indexKeyword]) % 26 + 'a', stdout);
			indexKeyword ++;
			if (indexKeyword >= numKeyword)
				indexKeyword = 0;
		}
		else fputc(input[i], stdout);
	}

	fputc('\n', stdout);
	free(keyword);
	return 0;
}

