#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

size_t square(int n)
{
	return n * n;
}
void square_end() {}

int main(int argc, char *argv[])
{
	size_t func_size = (char*)square_end - (char*)square;
	int fd = open("./libsquare.o", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0){
		printf("%s\n", strerror(errno));
		abort();
	}

	if(ftruncate(fd, func_size) <0)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	void* proj = mmap(NULL, func_size, PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
	if(proj == MAP_FAILED)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	memcpy(proj, (void*)square, func_size);
	return 0;
}
