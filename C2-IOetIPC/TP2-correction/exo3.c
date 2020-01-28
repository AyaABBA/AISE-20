#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd = open("./toto", O_RDWR | O_CREAT | O_APPEND, 0777 );

	if( fd < 0)
	{
		perror("open toto");
	}


	dup2(fd, STDOUT_FILENO);
	close(fd);

	int i;

	for( i = 0 ; i < 4096; i++)
		printf("%d\n", i);
	




	return 0;
}
