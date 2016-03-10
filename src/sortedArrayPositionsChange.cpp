/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr != NULL)
	{
		if (len > 0)
		{
			int low = 0, high = len - 1, i = 1, j = len - 2;
			while (Arr[low] < Arr[i++])
				low++;
			while (Arr[high] > Arr[j++])
				high--;
			if (low < high){
				int temp = Arr[high];
				Arr[high] = Arr[low];
				Arr[low] = temp;
			}
		}
		else
			return NULL;

	}
	else
	 return NULL;
}