#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
	if(argc != 2 )
		return 1;

	FILE * fd = fopen(argv[1], "w");

	if(!fd){
		perror("fopen");
		return 1;
	}

	char data[] = "Hello I/Os\n";
	size_t cnt;

	cnt = fwrite(data, sizeof(char), strlen(data), fd);
	
	if( cnt == 0)
	{
		perror("fread");
		return 1;
	}

	fclose(fd);

	return 0;
}



