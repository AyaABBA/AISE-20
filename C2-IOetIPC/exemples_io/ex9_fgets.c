#include <stdio.h>


int main(int argc, char ** argv){

	if( argc != 2 )
		return 1;

	FILE * fd = fopen(argv[1], "r");

	if(!fd){
		perror("fopen");
		return 1;
	}


	char buff[500];
	char * ret;
	int cnt = 0;

	while(1)
	{
		ret = fgets(buff, 500, fd);

		if(!ret)
		{
			if( feof(fd) )
			{
				/* EOF all OK*/
				break;
			}
			else
			{
				/* Error */
				perror("fgets");
				return 1;
			}
		}



		/* USE your buff here */
		fprintf(stdout, "%d : %s", ++cnt, ret );
	}




	fclose(fd);

	return 0;
}



