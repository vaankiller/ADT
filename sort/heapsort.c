#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#define LEFTCHILD(i) (2*(i))+1

static void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static void precDown(int *array, int i, int size)
{
	int child, tmp;

	for(tmp = array[i]; LEFTCHILD(i) < size-1; i = child)
	{
		child = LEFTCHILD(i);
		if(child != size-1 && array[child+1] > array[child])
			child++;
		if(tmp < array[child])
			array[i] = array[child];
		else
			break;
	}
	array[i] = tmp;
}

int heapsort(int *nums, int size)
{
	int i = 0;
	int j = 0;
	for(i = size/2; i >= 0; i--)
		precDown(nums, i, size);
	for(i = size-1; i > 0; i--)
	{
		swap(&nums[0], &nums[i]);
		precDown(nums, 0, i);
	}
}
