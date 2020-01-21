#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void sigusr_count(int sint)
{
	static int cnt = 0;
	fprintf(stderr, "CNT INT is : %d\n", ++cnt);

}

volatile int cont = 1;
pid_t child = 0;

void sigint(int sint)
{
	fprintf(stderr, "SIGINT\n");
	kill(child, SIGINT);
	/* We free the infinite while loop */
	cont = 0;
}


int main(int argc, char ** argv )
{
	child = fork();

	if( child == 0 )
	{
		signal(SIGUSR1, sigusr_count);

		while(1){}
	} else {
		signal(SIGINT, sigint);

		while(cont)
		{
			sleep(1);
			kill(child, SIGUSR1);
		}

		wait(NULL);
	}

	return 0;
}
