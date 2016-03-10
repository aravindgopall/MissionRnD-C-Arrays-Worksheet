/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
void swapstring(char *, char *);
void stringcopy(char *, char *);
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	for (int j = 0; j < len; j++)
	{
		for (int i = j+1; i < len; i++)
		{
			if (students[j].score < students[i].score)
			{
				students[i].score = students[i].score + students[j].score;
				students[j].score = students[i].score - students[j].score;
				students[i].score = students[i].score - students[j].score;
				swapstring(students[j].name, students[i].name);
			}
		
		}
	}
	return NULL;
}

void swapstring(char *string1, char * string2)
{
	int length1=0, length2=0;
	while (string1[length1] != '\0')
		length1++;
	while (string2[length2] != '\0')
		length2++;
	char *temp = (char *)malloc((length1 + 1)*sizeof(char));
	stringcopy(temp, string1);
	stringcopy(string1, string2);
	stringcopy(string1, temp);
}
void stringcopy(char *des, char *sor)
{
	int num = 0;
	while (sor[num] != '\0'){
		des[num] = sor[num];
		num++;
	}
	des[num] = '\0';
}