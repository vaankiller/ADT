#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 48271L
#define M 2147483647L

static unsigned int seed = 1;

double genRandom_overflow(void)
{
	seed = (A * seed) % M;
	return seed;
}

void init(unsigned long initVal)
{
	seed = initVal;
}

void main()
{
	long ret[1024] = {0};
	int i = 0;

	for(i = 0; i < 1024; i++)
	{
		ret[i] = genRandom_overflow();
	}

	for(i = 0; i < 1024; i++)
	{
		printf("%ld,", ret[i]);
	}
	return ;
}
