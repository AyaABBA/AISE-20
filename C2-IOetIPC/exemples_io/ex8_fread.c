#include <stdio.h>


int main(int argc, char ** argv){

	FILE * fd = fopen(argv[1], "r");

	if(!fd){
		perror("fopen");
		return 1;
	}


	char buff[500];
	size_t cnt;

	while( 1 )
	{
		cnt = fread(buff, sizeof(char), 500, fd);
		if( cnt == 0)
		{
			if( feof(fd) )
			{
				break;
			}
			else
			{
				perror("fread");
				return 1;
			}
		}

		/* USE your buff here */
	}


	fclose(fd);

	return 0;
}



