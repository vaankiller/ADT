#ifndef _HASH_H
#define _HASH_H

#include "list.h"
#define TABLESIZE 10007
#define MINTABLESIZE 10

typedef struct hashtbl hahstbl;
typedef struct hashtbl* hashtbl;
struct hashtbl {
	int tblsize;
	pListNode *lists;
};

int hash1(const char *s, int tableSize);
int hash2(const char *s, int tableSize);
int hash3(const char *s, int tableSize);

hashtbl initHashTbl(int size);
void destoryHashTbl(hashtbl h);
pListNode h_find(const char *s, hashtbl h);
void h_insert(const char *s, hashtbl h);

#endif
