#include <stdio.h>
#include <stdlib.h>
 
const char *test = "Where am i?";

static int sGlobalInit = 12345678;	// Static global(Initialized data)
static int sGlobalUninit;	// Static global(Uninitialized data)
int iGlobalInit = 0;		// Global(Initialized data)
int iGlobalUninit;		// Global(Uninitialized data)

int main(void)
{
	static int sLocalUninit;	// Static local(Uninitialized data)
	static int sLocalInit = 0;	// Static local(Initialized data)
	int  s1 = 24681357;	// Local variable(Stack)
	int  s2;	// Local variable(Stack)
	int* p1 = (int *)malloc(10 * sizeof(int));	// Local pointer (Heap)
	int* p2 = (int *)malloc(10 * sizeof(int));	// LOcal pointer (Heap)

	printf("Text(const string):\t\t%p\n", (void *) test);
	printf("Static global variable(Init):\t%p\n", (void *) &sGlobalInit);
	printf("Static global variable(Uninit):\t%p\n", (void *) &sGlobalUninit);
	printf("Global variable(Init):\t\t%p\n", (void *) &iGlobalInit);
	printf("Global variable(Uninit):\t%p\n", (void *) &iGlobalUninit);

	printf("Static local variable(Init):\t%p\n", (void *) & sLocalInit);
	printf("Static local variable(Uninit):\t%p\n", (void *) &sLocalUninit);

	printf("Local variable 1(Stack):\t%p\n", (void *) &s1);
	printf("Local variable 2(Stack):\t%p\n", (void *) &s2);
	printf("Local malloc variable 1(Heap):\t%p\n", (void *) p1);
	printf("Local malloc variable 2(Heap):\t%p\n", (void *) p2);

	return 0;
}
