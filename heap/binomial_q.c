#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binomial_q.h"

pforst_bino pbinoq_init(void)
{
	forst_bino* q;
	int i = 0;

	q = malloc(sizeof(struct forst_of_binomialq));
	if(!q)
		return NULL;

	q->currentsize = 0;
	for(i = 0; i < MAXSIZE; i++)
		q->trees[i] = NULL;

	return q;
}

pbinoq pbinoq_destory(pbinoq q)
{
	
}

pbinoq combine_trees(pbinoq p, pbinoq q)
{
	if(!p || !q)
		return NULL;

	if(p->elem > q->elem)
		return combine_trees(q, p);
	else
	{
		q->nextsib = p->left;
		p->left = q;
	}
	return p;
}

pforst_bino merge_trees(pforst_bino master, pforst_bino slave)
{
	pbinoq pm, ps, carry = NULL;
	int i, j;

	if(master->currentsize + slave->currentsize > MAXCAPA)
		return NULL;

	master->currentsize += slave->currentsize;
	for(i = 0, j = 1; j <= master->currentsize; i++, j += 2)
	{
		pm = master->trees[i];
		ps = slave->trees[i];

		switch(!!pm + 2*!!ps + 4*!!carry)
		{
			case 0:
			case 1:
				break;
			case 2:
				master->trees[i] = ps;
				slave->trees[i] = NULL;
				break;
			case 4:
				master->trees[i] = carry;
				carry = NULL;
				break;
			case 3:
				carry = combine_trees(ps, pm);
				master->trees[i] = slave->trees[i] = NULL;
				break;
			case 5:
				carry = combine_trees(ps, carry);
				master->trees[i] = NULL;
				break;
			case 6:
				carry = combine_trees(pm, carry);
				slave->trees[i] = NULL;
				break;
			case 7:
				master->trees[i] = carry;
				carry = combine_trees(ps, pm);
				slave->trees[i] = NULL;
				break;
		}
	}
	return master;
}

ElemType deletemin_trees(pforst_bino q)
{
	int i, j;
	int minidx;
	pforst_bino deletedQ;
	pbinoq oldroot, deletedT;
	ElemType min;

	if(!q)
		return 0;

	min = 0;
	for(i = 0; i < MAXSIZE; i++)
	{
		if(q->trees[i] && q->trees[i]->elem < min)
		{
			min = q->trees[i]->elem;
			minidx = i;
		}

	}

	deletedT = q->trees[minidx];
	oldroot = deletedT;
	deletedT = deletedT->left;
	free(oldroot);

	deletedQ = pbinoq_init();
	deletedQ->currentsize = (1 << minidx) - 1;
	for(j = minidx-1; j >=0; j--)
	{
		deletedQ->trees[j] = deletedT;
		deletedT = deletedT->nextsib;
		deletedQ->trees[j]->nextsib = NULL;
	}

	q->trees[minidx] = NULL;
	q->currentsize -= deletedQ->currentsize + 1;

	pbinoq_merge(q, deletedQ);
	return min;
}
