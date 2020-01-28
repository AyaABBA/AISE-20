#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	char buff[500];
	char * ret;
	int cnt = 0;

	while(1)
	{
		ret = fgets(buff, 500, stdin);

		if(!ret)
		{
			if( feof(stdin))
				return 0;	

			/* Error */
			perror("fgets");
			return 1;
		}



		/* USE your buff here */
		fprintf(stdout, "%s %d > %s", getenv("USER"), ++cnt, ret );
	}

	return 0;
}



