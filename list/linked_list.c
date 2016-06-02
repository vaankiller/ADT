#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void destory_list(pListNode l)
{
	if(l == NULL)
		return;
	if(l->next)
		return destory_list(l->next);
	else
		free(l);

	return;
}

pListNode list_find(pListNode l, ElemType x)
{
	if(l == NULL)
		return NULL;
	if(l->next == NULL)
	{
		if(l->elem == x)
			return l;
		else 
			return NULL;
	}
	return list_find(l->next, x);
}

pListNode list_insert_head(pListNode l, ElemType x)
{
	pListNode new = malloc(sizeof(struct ListNode));
	if(!new)
		return NULL;

	new->elem = x;
	new->next = l->next;
	l->next = new;
	return l;
}

pListNode list_insert_tail(pListNode l, ElemType x)
{

	pListNode new = malloc(sizeof(struct ListNode));
	if(!new)
		return NULL;

	new->elem = x;
	new->next = NULL;

	if(l == NULL)
		l = new;
	else
	{
		while(l->next)
			l = l->next;
		l->next = new;
	}
	return l;
}

pListNode list_delete_head(pListNode head)
{
	if(head == NULL  || head->next)
		return NULL;
	else
		head = head->next;
	return head;
}


pListNode list_delete_tail(pListNode head)
{
	if(head == NULL  || head->next)
		return NULL;
	pListNode pcur = head;
	while(pcur->next->next)
		pcur = pcur->next;
	pcur->next = NULL;
	return head;
}

pListNode list_delete_elem(pListNode l, ElemType elem)
{
	if(l == NULL)
		return NULL;
	else if(l->next == NULL)
	{
		if(l->elem == elem)
			return NULL;
		else
			return l;
	}
	else
		list_delete_elem(l->next, elem);
	return l;
}

int list_size(pListNode head)
{
	int cnt = 0;

	if(head == NULL)
		return 0;
	else
	{
		while(head)
		{
			cnt++;
			head = head->next;
		}
	}
	return cnt;
}


