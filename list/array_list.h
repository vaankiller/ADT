#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#define ARRAYSIZE 1024
#define ElemType int

typedef array_list arraylist
struct array_list {
	int size;
	ElemType* head;
};



#endif
