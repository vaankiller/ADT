#ifndef _LEFTIST_HEAP_H
#define _LEFTIST_HEAP_H

typedef int ElemType;
typedef struct left_heap_node l_heap;
typedef struct left_heap_node* plfheap;

struct left_heap_node {
	ElemType elem;
	plfheap left;
	plfheap right;
	int npl;
};

plfheap plfheap_init();
void plfheap_destory(plfheap q);
plfheap plfheap_insert(plfheap q, ElemType elem);
plfheap plfheap_deleteMin(plfheap q);
ElemType plfheap_findMin(plfheap q);
plfheap plfheap_merge_prep(plfheap p, plfheap q);
plfheap plfheap_merge(plfheap p, plfheap q);
plfheap swap_children(plfheap p);


#endif
