#include <sys/ioctl.h>
#include <stdio.h>
#include <signal.h>

void size_change(int sig )
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	printf("line %d\n", w.ws_row);
	printf("col %d\n", w.ws_col);
}


int main(int argc, char ** argv)
{
	signal(SIGWINCH, size_change);

	/* We block in expectation of CTRL+C */
	while(1){};
	
	return 0;
}
