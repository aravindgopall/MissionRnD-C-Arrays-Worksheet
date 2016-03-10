/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr != NULL)
	{
		if (len > 1)
		{

			for (int i = 0; i < len; i++)
			{
				int  j = i+1;
				while ( j < len)
				{
					if (Arr[i] == Arr[j]){
							for (int p = j; p < len - 1; p++){
								Arr[p] = Arr[p + 1];
								
					}
							len = len - 1;
					}
					j++;
				}
			}
			return len;
		}
		else if (len == 1)
			return 1;
		else if (len == 0)
			return 0;
		else
			return -1;
	}
	return -1;
 }