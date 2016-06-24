#include <stdlib.h>

#include "sort.h"

int shellsort(int* nums, int size)
{
	  int i, j, increment;
	  int tmp;

	  for(increment = size/2; increment > 0; increment /= 2)
	  {
		  for(i = increment; i < size; i++)
		  {
			  tmp = nums[i];
			  for(j = i; j >= increment; j -= increment)
			  {
				  if(tmp < nums[j-increment])
					  nums[j] = nums[j-increment];
				  else
					  break;
			  }
			  nums[j] = tmp;
		  }
	  }
	  return 0;
}
