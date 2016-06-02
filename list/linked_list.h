#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef int ElemType;
typedef struct ListNode ListNode;
typedef struct ListNode* pListNode;

struct ListNode {
	ElemType elem;
	ListNode *next;
};

struct DListNode {
	ElemType elem;
	ListNode* pre;
	ListNode* next;
};

void destory_list(pListNode l);
pListNode list_find(pListNode l, ElemType x);
pListNode list_insert_head(pListNode l, ElemType x);
pListNode list_insert_tail(pListNode l, ElemType x);
pListNode list_delete_head(pListNode head);
pListNode list_delete_tail(pListNode head);
pListNode list_delete_elem(pListNode l, ElemType elem);

#endif
