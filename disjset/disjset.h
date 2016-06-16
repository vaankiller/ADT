#ifndef _DISJSET_H
#define _DISJSET_H

#define numSets 10

typedef int djset[numSets+1];
typedef int ElemType;

void djset_init(djset s);
void djset_union_normal(djset s, ElemType l, ElemType r);
void djset_union_height(djset s, ElemType l, ElemType r);
ElemType djset_find(djset s, ElemType x);
ElemType djset_find_rar(djset s, ElemType x);



#endif
