#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

//#define _XOPEN_SOURCE
//#include <unistd.h>

#define _GNU_SOURCE
#include <crypt.h>

// Linux dictionary file path: /usr/share/dict/words
#define DIC_FILE_PATH		"/usr/share/dict/words"
#define BUF_SIZE		128

bool CryptCrack(const char *pPassword, const char *pCiphertext);

int main(int argc, char *argv[])
{
	FILE *pDicFile;
	int charInput, index = 0;
	char word[BUF_SIZE];

	if (argc != 2)
	{
		printf("Parameter number error.\n");
		return 1;
	}

	if (strlen(argv[1]) != 13)
	{
		printf("Ciphertext length error.(Should be 13 characters)\n");
		return 1;
	}

	pDicFile = fopen(DIC_FILE_PATH, "r");
	if (pDicFile == NULL)
	{
		printf("Cannot find dictionary file: %s\n", DIC_FILE_PATH);
		return 1;
	}

	do
	{
		charInput = fgetc (pDicFile);
		if (charInput == '\n')
		{
			word[index] = '\0';
			index = 0;

			// Assume passwords are no longer than 8 characters long
			if (strlen(word) <= 8)
			{
				//printf("%s\n", word);
				if (CryptCrack(word, argv[1]))
				{
					printf("Password: %s\n", word);
					break;
				}
			}
		}

		if (isprint(charInput))
		{
			if (index < (BUF_SIZE - 1))
				word[index ++] = (char) charInput;
			else
			{
				word[BUF_SIZE - 1] = '\0';
				printf("Word is too long: %s\n", word);
				index = 0;
			}
		}
	}
	while (charInput != EOF);

	fclose(pDicFile);
	return 0;
}

const char tableSalt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";

bool CryptCrack(const char *pPassword, const char *pCiphertext)
{
	char *pResult;
	char salt[] = "AA";
	int i, j;

	for (i = 0; i < 64; i ++)
		for (j = 0; j < 64; j ++)
		{
			salt[0] = tableSalt[i];
			salt[1] = tableSalt[j];
			pResult = (char *) crypt(pPassword, salt);
			if (strcmp(pResult, pCiphertext) == 0)
				return true;
		}
	return false;
}

