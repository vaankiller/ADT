#ifndef _HASH_QUAD_H
#define _HASH_QUAD_H

#define MINTBLSIZE 10007

typedef struct hashtbl* hashtbl;
typedef struct cell cell;
typedef enum info info;
typedef char* ElemType;

enum info {
	LEGITIMATE,
	EMPTY,
	DELETED,
};

struct hashtbl {
	int size;
	cell* cells;
};

struct cell {
	ElemType elem;
    info state;
};

hashtbl h_init(int tablesize);
int h_find(ElemType key, hashtbl h);
void h_insert(ElemType key, hashtbl h);
hashtbl rehash(hashtbl h);

#endif
