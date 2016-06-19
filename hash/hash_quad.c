#include <stdio.h>
#include <stdlib.h>

#include "hash_quad.h"

hashtbl h_init(int tblsize)
{
	if(tblsize < MINTBLSIZE)
		return NULL;
	
	hashtbl h = malloc(sizeof(struct hashtbl));
	if(!h)
		return NULL;
	
	h->size = tblsize; //!!!h->size = nextprime(tblsize);
	h->cells = malloc(sizeof(struct cell) * tblsize);
	if(!h->cells)
		return NULL;

	int i = 0;
	for(i = 0; i < tblsize; i++)
		h->cells[i].state = EMPTY;

	return h;
}

int h_find(ElemType key, hashtbl h)
{
	if(key == NULL)
		return -1;

	int pos = hash(key, h);
	int collisionNum = 0;

	while(h->cells[pos].state != EMPTY && h->cells[pos].elem != key)
	{
		pos += 2 * (++collisionNum) - 1;
		if(pos >= h->size)
			pos -= h->size;
	}
	return pos;
}

void h_insert(ElemType key, hashtbl h)
{
	int pos;

	pos = h_find(key, h);
	if(h->cells[pos].state != LEGITIMATE)
	{
		h->cells[pos].state = LEGITIMATE;
		h->cells[pos].elem = key;
	}
}

hashtbl rehash(hashtbl h)
{
	if(h == NULL)
		return NULL;

	int oldsize = h->size;
	cell* oldcells = h->cells;
	int i = 0;

	hashtbl newh = h_init(2 * oldsize);
	if(newh == NULL)
		return NULL;

	for(i = 0; i < oldsize; i++)
	{
		if(oldcells[i].state == LEGITIMATE)
			h_insert(oldcells[i].elem, newh);
	}

	free(oldcells);
	return newh;
}	

