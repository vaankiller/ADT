#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

hashtbl initHashTbl(int size)
{
	hashtbl h;
	int i;

	if(size < MINTABLESIZE)
		return NULL;

	h = (hashtbl)malloc(sizeof(struct hashtbl));
	if(!h)
		return NULL;

	h->tblsize = size; //nextPrime(size);
	h->lists = malloc(sizeof(pListNode) * h->tblsize);
	if(!h->lists)
		return NULL;

	for(i = 0; i < h->tblsize; i++)
	{
		h->lists[i] = malloc(sizeof(struct ListNode));
		if(h->lists[i] == NULL)
			return NULL;
		else
			h->lists[i]->next = NULL;
	}
	return h;
}

void destoryHashTbl(hashtbl h)
{
	if(!h)
		return;
	int i,j;

	for(i = h->tblsize; i > 0; i--)
	{
		if(h->lists[i]->next == NULL)
			free(h->lists);
		else
		{
			pListNode tmp = h->lists[i];
			while(h->lists[i])
			{
				h->lists[i] = h->lists[i]->next;
				free(h->lists[i]);
			}
			free(tmp);
		}
	}
	return;
}

pListNode h_find(const char *s, hashtbl h)
{
	if(!s || !h)
		return NULL;

	pListNode l;
	pListNode p;

	l = h->lists[hash(s, h->tblsize)];
	p = l->next;
	while(p && !strcmp(s, p->elem))
		p = p->next;
	return p;
}

// colision reslove 1 : sperate chainning
void h_insert(const char *s, hashtbl h)
{
	if(!s || !h)
		return ;

	pListNode plist = h_find(s, h);

	if(plist != NULL)
	{
		plist = h->lists[hash(s, h->tblsize)];
		pListNode pinsert = malloc(sizeof(struct ListNode));
		if(!pinsert)
			return ;
		else
		{
			strcmp(pinsert->elem, s);
			pinsert->next = plist->next;
			plist->next = pinsert;
		}
	}
	return;
}

// solution 2 open address hashing
// 1. linear detect		(hash(x) + f(i)) mod tblsize, normally f(i)=i
// 2. square detect   	(hash(x) + f(i)^2) mod tblsize
// 3. double hashing	(f(i)= i*hash_2(x))
// hashquad.c,haahquad.h









//solution 3 rehash













//extendible hashing 
int hash1(const char *s, int tableSize)
{
	unsigned int sum = 0;

	while(*s != 0)
	{
		sum += *s++;
	}
	return sum % tableSize;
}

int hash2(const char *s, int tableSize)   //at least 3 alpha
{
	return (s[0] + s[1]*27 + s[2]*729) % tableSize;
}

int hash3(const char *s, int tableSize)
{
	unsigned int hashVal = 0;

	while(*s != 0)
		hashVal = (hashVal << 5) + *s++;

	return hashVal % tableSize;
}


