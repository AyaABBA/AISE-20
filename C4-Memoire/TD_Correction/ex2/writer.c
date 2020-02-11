#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

static void catch(int sig)
{
	printf("Got the signal %d\n", sig);
	if(sig != SIGUSR1)
		abort();
}

int main(int argc, char *argv[])
{
	int pid = getpid();
	printf("writer PID: %d\n", pid);
	int fd = open("./file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0){
		printf("%s\n", strerror(errno));
		abort();
	}

	if(ftruncate(fd, 64) <0)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	void* proj = mmap(NULL, 64, PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
	if(proj == MAP_FAILED)
	{
		printf("%s\n", strerror(errno));
		abort();
	}

	memcpy(proj, &pid, sizeof(int));
	
	if(signal(SIGUSR1, catch) == SIG_ERR)
	{
		printf("Error setting the handler !\n");
		abort();
	}

	printf("Now wait...\n");
	pause();
	munmap(proj, 64);
	return 0;
}
