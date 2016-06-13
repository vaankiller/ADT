#ifndef _TREE_H
#define _TREE_H

typedef int ElemType;
typedef struct TreeNode TreeNode;
typedef struct TreeNode* pTreeNode;

struct TreeNode {
	ElemType elem;
	TreeNode *firstchild;
	TreeNode *nextsib;
};

typedef struct BTreeNode BTreeNode;
typedef struct BTreeNode* pBTreeNode;
struct BTreeNode {
	ElemType elem;
	BTreeNode *left;
	BTreeNode *right;
};

typedef struct BTreeNode BSTreeNode;
typedef struct BTreeNode* pBSTreeNode;
typedef struct BTreeNode* pBSTreeNode;

//BSTree Function statement
pBSTreeNode create(void);
pBSTreeNode destory(pBSTreeNode root);
pBSTreeNode find(pBSTreeNode root, ElemType elem);
pBSTreeNode findmin(pBSTreeNode root);
pBSTreeNode findmax(pBSTreeNode root);
pBSTreeNode insert(pBSTreeNode root, ElemType elem);
pBSTreeNode delete(pBSTreeNode root, ElemType elem);
ElemType retrieve(pBSTreeNode p);



//AVL tree 
typedef struct AVLTreeNode  AVLTreeNode;
typedef struct AVLTreeNode* pAVLTreeNode;
struct AVLTreeNode {
	ElemType elem;
	AVLTreeNode* left;
	AVLTreeNode* right;
	int height;      //height, absolute height
};

static int Height(pAVLTreeNode t);
static pAVLTreeNode singleRotateLeft(pAVLTreeNode t);
static pAVLTreeNode singleRotateRight(pAVLTreeNode t);
static pAVLTreeNode doubleRotateLeft(pAVLTreeNode t);
static pAVLTreeNode doubleRotateRight(pAVLTreeNode t);
pAVLTreeNode avl_insert(pAVLTreeNode t, ElemType elem);
pAVLTreeNode avl_delete(pAVLTreeNode t, ElemType elem);
pAVLTreeNode avl_create(void);
pAVLTreeNode avl_destory(pAVLTreeNode t);
pAVLTreeNode avl_find(pAVLTreeNode t, ElemType elem);
pAVLTreeNode avl_findmin(pAVLTreeNode t);
pAVLTreeNode avl_findmax(pAVLTreeNode t);
ElemType avl_retrieve(pAVLTreeNode t);













#endif

