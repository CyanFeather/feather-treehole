#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{
// Open memory
int fd = open("/dev/mem", O_RDWR);
if (fd < 0)
{
printf("Open memory error!\n");
return -1;
}

// Map physical memory base ~ base + size bytes
int base = 0;
int size = 10;
char *mem;
mem = (char *) mmap((void *)base, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

if (mem == MAP_FAILED)
{
printf("Mmap error!\n");
return 1;
}
// Read memory 
for (int i = 0; i < size; i ++)
printf("mem[%d]: %#x\n", i, (unsigned char) mem[i]);

/*
// Write memory
char *buff = "HELLO";
memcpy(mem, buff, 5);

// Read memory again
for (int i = 0; i < size; i ++)
printf("mem[%d]: %#x\n", i, (unsigned char)mem[i]);
*/
// Destroy map memory
munmap(mem, size);

// Close memory
close(fd);
return 0;
}

