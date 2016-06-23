#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

int Msort(int* ret, int* tmp, int l, int r)
{
	if(!ret || !tmp || l > r)
		return -1;
	int i = 0;

	int mid = (l + r)/2;
	if(l < r)
	{
		Msort(ret, tmp, l, mid);
		Msort(ret, tmp, mid+1, r);
		mergecore(ret, tmp, l, mid+1, r);
	}
	return 0;
}

int mergecore(int* ret, int* tmp, int lpos, int rpos, int rend)
{
	if(!ret || !tmp)
		return -1;

	int lend = rpos-1;
	int tmppos = lpos;
	int i = 0;
	int numsize = rend-lpos+1;

	while(lpos <= lend && rpos <= rend)
	{
		if(ret[lpos] > ret[rpos])
			tmp[tmppos++] = ret[rpos++];
		else
			tmp[tmppos++] = ret[lpos++];
	}

	while(lpos <= lend)
		tmp[tmppos++] = ret[lpos++];
	while(rpos <= rend)
		tmp[tmppos++] = ret[rpos++];
	for(i = 0; i < numsize; i++,rend--)
		ret[rend] = tmp[rend];
	return 0;
}

int mergesort(int* nums, int size)
{
	int *meta = malloc(sizeof(int)*size);
	if(!meta)
		return -1;
	else
	{
		Msort(nums, meta, 0, size-1);
		free(meta);
	}
	return 0;
}
