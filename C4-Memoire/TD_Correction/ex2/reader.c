#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int pid = getpid();
	int fd = open("./file.txt", O_RDONLY);
	if(fd < 0){
		printf("%s\n", strerror(errno));
		abort();
	}

	void* proj = mmap(NULL, 64, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
	if(proj == MAP_FAILED)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	memcpy(&pid, proj, sizeof(int));

	kill(pid, SIGUSR1);
	munmap(proj, 64);
	
	return 0;
}
