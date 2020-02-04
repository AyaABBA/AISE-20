#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t count = 0;

char* rev(const char*s)
{
	char c;
	int i, sz = strlen(s)-1;
	char* t = malloc(sz+1);
	for(i=0; i <= sz; i++)
	{
		t[i] = s[sz-i];
	}
	t[sz+1] = '\0';
	return t;
}

int mylib_puts(const char *s)
{
	char* copy = rev(s);
	count += strlen(copy);
	printf("Size of next puts: %d bytes\n", strlen(copy));
	int ret = puts(copy);
	free(copy);

	return ret;

}

size_t mylib_nbchars()
{
	return count;
}
