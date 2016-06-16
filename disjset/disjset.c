#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disjset.h"


void djset_init(djset s)
{
	if(!s)
		return;

	int i;
	for(i = 1; i < numSets; i++)
		s[i] = 0;

	return;
}

void djset_union_normal(djset s, ElemType master, ElemType slave)
{
	s[slave] = master;
	return;
}

void djset_union_height(djset s, ElemType l, ElemType r)
{
	if(!s)
		return ;

	if(s[r] < s[l])
		s[l] = s[r];
	else
	{
		if(s[r] == s[l])
			s[l]--;
		s[r] = l;
	}
	return ;
}

ElemType djset_find(djset s, ElemType x)
{
	if(!s)
		return -1;

	if(s[x] <= 0)
		return x;
	else
		return djset_find(s, s[x]);
}

ElemType djset_find_rar(djset s, ElemType x)
{
	if(s[x] <= 0)
		return x;
	else
		return s[x] = djset_find_rar(s, s[x]);
}
