#include <unistd.h>
#include <stdio.h>
int main(int argc,char **argv)
{
    if(fork())
        printf("This is parent process.\n");
    else
        printf("This is child process.\n");

    return 0;
}
