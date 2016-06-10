#ifndef _BIN_HEAP_H
#define _BIN_HEAP_H

#define MINDATA 0
#define MINPRIQSIZE 3

typedef int ElemType;
typedef struct bin_heap* priQ;

struct bin_heap {
	int capacity;
	int size;
	ElemType* elems;
};


priQ priQ_init(int max);
void priQ_destory(priQ q);
void priQ_empty(priQ q);
void priQ_insert(priQ q, ElemType elem);
ElemType priQ_deleteMin(priQ q);
ElemType priQ_findMin(priQ q);
int priQ_isempty(priQ q);
int priQ_isfull(priQ q);

#endif
