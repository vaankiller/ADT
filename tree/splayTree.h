#ifndef _SPLAYTREE_H
#define _SPLAYTREE_H

#include "tree.h"

typedef struct splayNode* splayTree;
typedef struct splayNode {
	ElementType Elem;
	splayTree left;
	splayTree right;
} splayNode;



splayTree splay_makeEmpty(splayTree t);
splayTree splay_find(splayTree t);
splayTree splay_findmin(splayTree t, ElementType x);
splayTree splay_findmax(splayTree t);
splayTree splay_init(void);
splayTree splay_insert(splayTree t, ElementType x);
splayTree splay_remove(splayTree t, ElementType x);
ElementType splay_retrieve(splayTree t);

#endif
