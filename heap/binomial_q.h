#ifndef _BINOMIAL_Q_H
#define _BINOMIAL_Q_H

#define MAXSIZE 14
#define MAXCAPA 32765
#define MINNUM -1

typedef struct binomialq_node binoq;
typedef struct binomialq_node* pbinoq;
typedef int ElemType;

struct binomialq_node {
	ElemType elem;
	pbinoq left;
	pbinoq nextsib;
};

typedef struct forst_of_binomialq forst_bino;
typedef struct forst_of_binomialq* pforst_bino;
struct forst_of_binomialq {
	int currentsize;
	pbinoq trees[MAXSIZE];
};

pbinoq combine_trees(pbinoq p, pbinoq q);
pforst_bino merge_trees(pforst_bino p, pforst_bino q);
ElemType deletemin_trees(pforst_bino q);
pforst_bino pbinoq_init(void);
pbinoq pbinoq_destory(pbinoq q);

#endif
