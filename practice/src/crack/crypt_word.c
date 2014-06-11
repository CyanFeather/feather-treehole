#include <stdio.h>

//#define _XOPEN_SOURCE
//#include <unistd.h>

#define _GNU_SOURCE
#include <crypt.h>

int main(int argc, char** argv)
{
	if (argc !=3)
	{
		printf("Parameter number error.\n");
		return 1;
	}

	printf("%s\n", (char *)crypt(argv[1], argv[2]));
	return 0;
}

