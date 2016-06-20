#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

int selection(int* nums, int size)
{
	int i, j, tmp;

	if(nums == NULL)
		return -1;

	for(i = 1; i < size; i++)
	{
		tmp = nums[i];
		for(j = i; nums[j-1] > tmp && j > 0; j--)
			nums[j] = nums[j-1];
		nums[j] = tmp;
	}
	return 0;
}
