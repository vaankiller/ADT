#include "splayTree.h""

static splayNode* NullNode = NULL;

splayTree splay(splayTree pos, ElemType item)
{
	static struct splayNode header;
	TreeNode* lTreeMax, rTreeMin;

	header.left = header.right = NullNode;
	lTreeMax = rTreeMin = &header;
	NullNode->element = item;

	while(item != pos->elem)
	{
		if(item < pos->elem)
		{
			if(item < pos->left->elem)
				pos = singleRotateWithLeft(pos);
			if(pos->left == NullNode)
				break;
			/* link right */
			rTreeMax->left = pos;
			rTreeMIn = pos;
			pos = pos->left;
		}
		else
		{
			if(item > pos->right->elem)
				pos = singleRotateWithRight(pos);
			if(x->right == NullNode)
				break;
			/* link left */
			lTreeMax->right = pos;
			lTreeMax = pos;
			pos = pos->right;
		}
	}

	/* reassemble */
	lTreeMax->right = pos->left;
	rTreeMin->left = pos->right;
	pos->left = header.right;
	pos->right = header.left;

	return pos;
}
}

splayTree splay_makeEmpty(splayTree t)
splayTree splay_find(splayTree t)
splayTree splay_findmin(splayTree t, ElementType x)
splayTree splay_findmax(splayTree t)
splayTree splay_init(void)
{
	if(NullNode == NULL)
	{
		NullNode = malloc(sizeof(struct splayNode));
		if(NullNode == NULL)
			exit(0);
		NullNode->left = NULL;
		NullNode->rightt = NULL;
	}
	return NullNode;
}

splayTree splay_insert(splayTree t, ElementType x)
splayTree splay_remove(splayTree t, ElementType x)
ElementType splay_retrieve(splayTree t)
