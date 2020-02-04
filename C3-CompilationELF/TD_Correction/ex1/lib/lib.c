#include <stdio.h>
#include <string.h>
size_t count = 0;

int mylib_puts(const char *s)
{
	count += strlen(s);
	printf("Size of next puts: %lu bytes\n", count);
	return puts(s);
}

size_t mylib_nbchars()
{
	return count;
}
