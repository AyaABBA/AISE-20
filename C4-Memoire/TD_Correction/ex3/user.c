#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

int main(int argc, char *argv[])
{
	int fd = open("./libsquare.o", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0){
		printf("%s\n", strerror(errno));
		abort();
	}

	void* proj = mmap(NULL, SIZE, PROT_READ|PROT_EXEC, MAP_FILE | MAP_SHARED, fd, 0);
	if(proj == MAP_FAILED)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	size_t (*square_fn)(int n);
	square_fn = (size_t(*)(int))proj;

	int i = 4;
	printf("square(%d) = %lu\n", i, square_fn(i));
	return 0;
}
