#include <mylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	char s[64];
	snprintf(s, 64, "my PID is %d", getpid());
	mylib_puts(s);

	printf("Total written bytes: %lu\n", mylib_nbchars());
	return 0;
}
