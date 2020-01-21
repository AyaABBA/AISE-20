#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

static int cnt_CONT = 0;
static int cnt_PIPE = 0;

void sig_count(int sig)
{
	switch(sig)
	{
		case SIGCONT:
			fprintf(stderr, "CHILD HAD SIGCONT\n");
			cnt_CONT++;
			break;
		case SIGPIPE:
			fprintf(stderr, "CHILD HAD SIGPIPE\n");
			cnt_PIPE++;
			break;
	}

}

void child_int(int sint)
{
	fprintf(stderr, "SIGCONT %d SIGINT %d\n", cnt_CONT, cnt_PIPE);
	exit(0);
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
		signal(SIGCONT, sig_count);
		signal(SIGPIPE, sig_count);
		signal(SIGINT, child_int);

		while(1){}
	} else {
		signal(SIGINT, sigint);

		int cnt = 0;

		while(cont)
		{
			sleep(1);
			if(!(rand()%2))
			{
				kill(child, SIGCONT);
			}
			else
			{
				kill(child, SIGPIPE);
			}

			if( cnt++ == 5)
				break;
		}

		kill(child, SIGINT);
	}

	return 0;
}
