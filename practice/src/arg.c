#include <stdio.h>

int main(int argc, char *argv[])
{
	int index;
	printf("Argument number: %d\n", argc);
	for (index = 0; index < argc; index ++)
		printf("Argument %d: %s\n", index + 1, argv[index]);

	return 0;
}
