#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leftist_heap.h"


plfheap plfheap_init()
{
	plfheap root = malloc(sizeof(struct left_heap_node));
	if(!root)
		return NULL;
	
	root->left = NULL;
	root->right = NULL;
	root->npl = 0;

	return root;
}

void plfheap_destory(plfheap q)
{
	if(!q)
		return ;

	if(q->left)
		plfheap_destory(q->left);
	else if(q->right)
		plfheap_destory(q->right);
	else
	{
		free(q);
		q = NULL;
	}
	return;
}

plfheap plfheap_insert(plfheap q, ElemType elem)
{
	if(!q)
		return NULL;
	
	plfheap node = malloc(sizeof(plfheap));
	if(!node)
		return;
	else
	{
		node->npl = 0;
		node->elem = elem;
		node->left = NULL;
		node->right = NULL;
		q = plfheap_merge_prep(q, node);
	}
	return q;
}

plfheap plfheap_deleteMin(plfheap q)
{
	if(!q)
		return NULL;
	
	plfheap pleft = q->left;
	plfheap pright = q->right;

	free(q);
	q = NULL;

	return plfheap_merge_prep(pleft, pright);
}

ElemType plfheap_findMin(plfheap q)
{
	if(!q)
		return 0;

	return q->elem;
}

int plfheap_isempty(plfheap q)
{
	return (q==NULL?0:1);
}

plfheap plfheap_merge_prep(plfheap p, plfheap q)
{
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	if(p->elem < q->elem)
		return plfheap_merge(p, q);
	else
		return plfheap_merge(q,p);

}


plfheap plfheap_merge(plfheap p, plfheap q)
{
	if(!p && !q)
		return NULL;

	if(p->left == NULL)
		p->left = q;
	else
	{
		p->right = plfheap_merge_prep(p->right, q);
		if(p->left->npl < p->right->npl)
			swap_children(p);

		p->npl = p->right->npl + 1;
	}
	return p;
}

plfheap swap_children(plfheap p)
{
	if(!p)
		return p;
	else
	{
		plfheap tmp = NULL;
		tmp = p->left;
		p->left = p->right;
		p->right = p->left;
	}
	return p;
}

