#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
	char * command = strdup("ls -la");
	
	char * arg[32];
	char * ret = NULL;

	ret = strtok(command, " ");
	
	int i = 0;
	do
	{
		if(ret)
			arg[i] = strdup(ret);
		ret = strtok(NULL, " ");
		i++;
	}while(ret != NULL);

	arg[i] = NULL;

	i = 0;

	while(arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}

	execvp(arg[0], arg);

}
