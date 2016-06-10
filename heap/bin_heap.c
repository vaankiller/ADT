#include <stdio.h>
#include <stdlib.h>

#include "bin_heap.h"

priQ priQ_init(int maxsize)
{
	if(maxsize < MINPRIQSIZE)
		return NULL;
	
	priQ q = malloc(sizeof(struct bin_heap));
	if(!q)
		return NULL;

	q->elems = malloc(sizeof(ElemType) * maxsize + 1);
	if(!q->elems)
		return NULL;

	q->capacity = maxsize;
	q->size = 0;
	q->elems[0] = MINDATA;
	
	return q;
}

void priQ_destory(priQ q)
{
	if(!q)
		return;

	free(q->elems);
	free(q);

	return ;
}

void priQ_empty(priQ q)
{
	if(!q)
		return ;

	int i = 0;

	for(i = 0; i < q->size; i++)
		q->elems[i] = 0;
	return ;
}

void priQ_insert(priQ q, ElemType elem)
{
	int i = 0;

	if(!q)
		return ;

	if(priQ_isfull(q))
		return ;

	for(i = ++q->size; q->elems[i/2] > elem; i /= 2)
		q->elems[i] = q->elems[i/2];
	q->elems[i] = elem;
/*	no need to swap
	pos = ++q->size;
	q->elems[pos] = elem;
	while(pos > 1 && q->elems[pos] > q->elems[pos/2])
	{
		tmp = q->elems[pos/2];
		q->elems[pos/2] = q->elems[pos];
		q->elems[pos] = tmp;
	}
*/
	return ;
}

ElemType priQ_deleteMin(priQ q)
{
	int i,child;
	ElemType min,last;

	if(!q)
		return -1;

	if(priQ_ifempty(q))
		return -1;
	
	min = q->elems[1];
	last = q->elems[q->size--];

	for(i = 1; i * 2 < q->size; i = child)
	{
		child = i * 2;
		if(child != q->size && q->elems[child+1] < q->elems[child])
			child++;

		if(last > q->elems[child])
			q->elems[i] = q->elems[child];
		else
			break;
	}
	q->elems[i] = last;
	return min;
}

ElemType priQ_findMin(priQ q)
{
	if(!q)
		return -1;

	else if(priQ_isempty(q))
		return -1;
	else 
		return q->elems[1];
}

int priQ_isempty(priQ q)
{
	if(!q)
		return -1;
	
	return q->size?0:1;
}

int priQ_isfull(priQ q)
{
	if(!q)
		return -1;

	return (q->size == q->capacity)?1:0;
}

