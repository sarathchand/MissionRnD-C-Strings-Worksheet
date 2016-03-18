/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int compare(char *str1, char *str2);
int verify(char *temp, char *str1);
void transfer(char *s, char *p);

char ** commonWords(char *str1, char *str2) {
	int i, j, q, p = 0, k = 0;
	char *temp1, *temp2;
	char **x = (char **)malloc(sizeof(char)* 31);
	if ((str1 == NULL) || (str2 == NULL))
		return NULL;
	for (i = 0; i < 31; i++)
	{
		x[i] = (char*)malloc(sizeof(char)* 31);
	}
	temp1 = (char*)malloc(sizeof(char));
	temp2 = (char*)malloc(sizeof(char));
	for (i = 0; (str1[i] != '\0'); i++)
	{
		if (!(str1[i] == ' '))
		{
			temp1[p] = str1[i];
			p++;
		}

		else
		{
			temp1[p] = '\0';

			q = compare(temp1, str2);


			p = 0;
			if (q == 1)
			{
				transfer(x[k], temp1);
				k++;


			}

			temp1 = (char*)malloc(sizeof(char));

		}
	}
	temp1[p] = '\0';
	q = compare(temp1, str2);
	if (q == 1)
	{
		transfer(x[k], temp1);
		k++;
	}
	temp1 = (char*)malloc(sizeof(char));


	if (k == 0)
	{
		return NULL;
	}
	return x;
}
int compare(char *str1, char *str2)
{
	int i = 0, p = 0, q, k;
	char *temp;
	temp = (char*)malloc(sizeof(char));

	while (str2[i] != '\0')
	{
		if (str2[i] != ' ')
		{
			temp[p] = str2[i];


			p++;
		}
		else
		{
			temp[p] = '\0';
			k = verify(temp, str1);
			if (k == 1)
			{
				return 1;
			}
			p = 0;
		}
		i++;
	}
	temp[p] = '\0';
	k = verify(temp, str1);
	if (k == 1)
	{
		return 1;
	}
	return 0;


}
int verify(char *temp, char *str1)
{
	int i, j, p = 0, c = 0;
	for (i = 0; temp[i] != '\0'; i++);
	for (j = 0; str1[j] != '\0'; j++);
	if (temp[0] == NULL)
	{
		return -1;
	}
	while (temp[p] != '\0')
	{
		if (temp[p] == str1[p])
		{
			c++;
		}
		p++;
	}
	if ((c == i) && (c == j))
	{
		return 1;
	}
	else
	{
		return -1;
	}


}
void transfer(char *s, char *p)
{
	int i;
	for (i = 0; p[i] != '\0'; i++)
	{
		s[i] = p[i];
	}
	s[i] = '\0';
}