#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	const size_t max = 1024 * 1024;
	int i, count = 100;
	for(i = 0; i < count; i++)
	{
		size_t sz = rand() % max;
		fprintf(stderr, "* malloc(%lu)\n", sz);
		void* ptr = malloc(sz);
		if(!ptr)
			abort();
		bzero(ptr, sz);
		((char*)(ptr))[sz-1] = 'a';

		free(ptr);
	}
	return 0;
}
