#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

pBSTreeNode create(void)
{
	pBSTreeNode root = malloc(sizeof(BSTreeNode));
	if(!root)
		exit(-1);
	return root;
}

pBSTreeNode destory(pBSTreeNode t) 
{
	if(t != NULL)
	{
		destory(t->left);
		destory(t->right);
		free(t);
		t = NULL;
	}
	return NULL;
}

pBSTreeNode find(pBSTreeNode t, ElemType elem) 
{
	if(t == NULL)
		return NULL;

	if(elem < t->elem)
		find(t->left, elem);
	else if(elem > t->elem)
		find(t->right, elem);
	else
		return t;
}

pBSTreeNode findmin(pBSTreeNode t) 
{
	if(!t)
		return NULL;

	while(t->left)
		t = t->left;

	return t;
}

pBSTreeNode findmax(pBSTreeNode t) 
{
	if(t == NULL)
		return NULL;
	else if(t->right == NULL)
		return t;
	else
		return findmax(t->right);
}
//isert and delete may change the root node, so we return the root node address
pBSTreeNode insert(pBSTreeNode t, ElemType elem) 
{
	if(t == NULL)
	{
		t = malloc(sizeof(pBSTreeNode));
		t->elem = elem;
		t->left = t->right = NULL;
	}
	else if(elem < t->left->elem)
		t->left = insert(t->left, elem);
	else
		t->right = insert(t->right, elem);

	return t;
}

pBSTreeNode delete(pBSTreeNode t, ElemType elem) 
{
	pBSTreeNode pdelete = find(t, elem);
	pBSTreeNode pright_min = NULL;
	if(pdelete == NULL)
		return NULL;
	else
	{
		if(pdelete->left && pdelete->right)
		{
			pright_min = findmin(pdelete->right);
			pdelete->elem = pright_min->elem;
			t->right = delete(t->right, pright_min->elem);
		}
		else if(pdelete->left == NULL)
			pdelete = pdelete->right;
		else if(pdelete->right == NULL)
			pdelete = pdelete->left;
		free(pdelete);
	}
	return t;
}

ElemType retrieve(pBSTreeNode t) 
{
	if(!t)
		return t->elem;
	else
		exit(-1);
}

//AVL tree ............................
static int Height(pAVLTreeNode t)
{
	if(!t)
		return -1;
	else
		return t->height;
}

pAVLTreeNode avl_insert(pAVLTreeNode t, ElemType elem)
{
	if(t == NULL)
	{
		t = malloc(sizeof(pBSTreeNode));
		t->height = 0;
		t->elem = elem;
		t->left = t->right = NULL;
	}
	else if(elem < t->left->elem)
	{
		t->left = avl_insert(t->left, elem);
		if(abs(Height(t->left) - Height(t->right) == 2))
		{
			if(elem < t->elem)
				t = singleRotateLeft(t);
			else
				t = doubleRotateRight(t);
		}
	}
	else
	{
		if(abs(Height(t->left) - Height(t->right) == 2))
		{
			t->right = avl_insert(t->right, elem);
			if(elem < t->elem)
				t = singleRotateLeft(t);
			else
				t = doubleRotateRight(t);
		}
	}

	t->height = max(Height(t->left),Height(t->right)) + 1;
	return t;
}

static pAVLTreeNode singleRotateLeft(pAVLTreeNode t)
{
	pAVLTreeNode newt;

	newt		= t->left;
	newt->left  = t->right;
	newt->right = t;

	t->height    = max(Height(t->left),Height(t->right)) + 1;
	newt->height = max(Height(newt->left),Height(newt->right)) + 1;
	return newt;
}

static pAVLTreeNode singleRotateRight(pAVLTreeNode t)
{
	pAVLTreeNode newt;

	newt		= t->right;
	newt->right = t->left;
	newt->left  = t;

	t->height    = max(Height(t->left),Height(t->right)) + 1;
	newt->height = max(Height(newt->left),Height(newt->right)) + 1;
	return newt;
}

static pAVLTreeNode doubleRotateLeft(pAVLTreeNode t)
{
	if(!t)
		return NULL;

	t->left = singleRotateRight(t->left);
	return singleRotateLeft(t->right);
}

static pAVLTreeNode doubleRotateRight(pAVLTreeNode t)
{
	if(!t)
		return NULL;

	t->right = singleRotateLeft(t->right);
	return singleRotateRight(t->left);
}

pAVLTreeNode avl_delete(pAVLTreeNode t, ElemType elem)
{

}
pAVLTreeNode avl_create(void)
{
	pAVLTreeNode root = malloc(sizeof(AVLTreeNode));
	if(!root)
		exit(-1);
	return root;
}
pAVLTreeNode avl_destory(pAVLTreeNode t)
{
	if(t != NULL)
	{
		avl_destory(t->left);
		avl_destory(t->right);
		free(t);
		t = NULL;
	}
	return NULL;
}

pAVLTreeNode avl_find(pAVLTreeNode t, ElemType elem)
{
	if(t == NULL)
		return NULL;

	if(elem < t->elem)
		avl_find(t->left, elem);
	else if(elem > t->elem)
		avl_find(t->right, elem);
	else
		return t;
}

pAVLTreeNode avl_findmin(pAVLTreeNode t)
{
	if(!t)
		return NULL;

	while(t->left)
		t = t->left;

	return t;
}

pAVLTreeNode avl_findmax(pAVLTreeNode t)
{
	if(t == NULL)
		return NULL;
	else if(t->right == NULL)
		return t;
	else
		return avl_findmax(t->right);
}

ElemType avl_retrieve(pAVLTreeNode t)
{
	if(!t)
		return t->elem;
	else
		exit(-1);
}
