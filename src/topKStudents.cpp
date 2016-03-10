/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<string.h>
struct student {
	char *name;
	int score;
};
int min_index(struct student *,int);
struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL)
		return NULL;
	if (len <= 0 || K <= 0)
		return NULL;

	struct student ** result= (student **)malloc((K)*sizeof(student));
	if (K >= len)
	{
		for (int i = 0; i < len; i++)
	         result[i] = &students[i];

		return  result;
	}
	if (K == 1)
	{
		int index = 0, min = students[0].score;
		for (int i = 1; i < len; i++)
		{
			if (min < students[i].score)
			{
				index = i;
				min = students[i].score;
			}
		}
		result[0] = &students[index];
		return result;
	}


		for (int i = K; i < len; i++)
		{
			int temp = min_index(students, K);
			if (students[temp].score < students[i].score)
			{
				students[temp].score = students[i].score;
			}
		}
		for (int i = 0; i < K; i++)
		{
			result[i] = &students[i];
		}

		return result;

	}

	int min_index(struct student *temp, int K)
{
	int min = temp[0].score, index = 0;
	for (int i = 1; i < K; i++)
	{
			if (min>temp[i].score)
			{
				min = temp[i].score;
				index = i;
			}
		
	}
	return index;
}