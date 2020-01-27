#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv )
{
	int pp[2];
	pipe(pp);

	pid_t child1 = fork();

	if( child1 == 0)
	{
		/* Replace stdout with the write end of the pipe */
		dup2(pp[1], STDOUT_FILENO);
		/* Close read end of the pipe */
		close(pp[0]);
		/* Run command */
		char * argv[] = {"cat", NULL};
		execvp( argv[0], argv);
	}
	else
	{
		pid_t child2 = fork();
	
		if(child2 == 0)
		{
			/* Replace stdin with the read end of the pipe */
			dup2(pp[0], STDIN_FILENO);
			/* Close write end of the pipe */
			close(pp[1]);
			/* Run command */
			char * argv[] = {"tac","-s", " ", NULL};
			execvp( argv[0], argv);
		}
		else
		{
			/* Close both end of the pipe */
			close(pp[0]);
			close(pp[1]);
			/* wait for two child */
			wait(NULL);
			wait(NULL);
		}
	}

	return 0;
}

