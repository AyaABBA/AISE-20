#include <stdio.h>


int main(int argc, char ** argv){

	FILE * fd = fopen(argv[1], "r");

	if(!fd){
		perror("fopen");
		return 1;
	}

	fclose(fd);

	return 0;
}



