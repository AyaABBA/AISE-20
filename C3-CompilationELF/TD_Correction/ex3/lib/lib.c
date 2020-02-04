#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <stdlib.h>

size_t nb_allocs = 0;
size_t nb_frees = 0;

void * malloc(size_t n)
{
	static void*(*real_malloc)(size_t) = NULL;
	if(!real_malloc)
	{
		real_malloc = (void*(*)(size_t))dlsym(RTLD_NEXT, "malloc");
		if(!real_malloc)
			abort();
	}
	nb_allocs++;
	return real_malloc(n);
}

void free(void *ptr)
{
	static void(*real_free)(void*) = NULL;
	if(!real_free)
	{
		real_free = (void(*)(void*))dlsym(RTLD_NEXT, "free");
		if(!real_free)
			abort();
	}
	nb_frees++;
	real_free(ptr);
}

__attribute__((constructor))
void initialize()
{
	printf("In custom Malloc library !\n");
}

__attribute__((destructor))
void finalize()
{
	printf("Made %lu allocations\n", nb_allocs);
	printf("Made %lu frees\n", nb_frees);
}
