/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void str_words_in_rev(char *input, int len);
void reverse(int i, int(j), char input[]);
int nextspace(int j, int len, char input[]);

	void str_words_in_rev(char *input, int len){
		int i, j, p, q;
		char t;
		p = len - 1;
		for (j = 0; j < (len) / 2; j++)
		{
			t = input[j];
			input[j] = input[p];
			input[p] = t;
			p--;
		}
		puts(input);
		i = 0;
		for (j = 0; j < len; j++)
		{
			if ((input[j] == ' ') && (i == 0))
			{
				reverse(i, j - 1, input);
				i = j + 1;
			}
			if (input[j] == ' ' && (i != 0))
			{
				q = nextspace(j + 1, len, input);
				reverse(j + 1, q - 1, input);
				i = q;
			}
			if ((j == len - 1))
			{
				reverse(i, j, input);
			}
		}

	}
	void reverse(int i, int(j), char input[])
	{
		int q;
		char t;
		q = i;
		//for (q = i; (q!=j); q++)
		while (q<j)
		{

			t = input[q];
			input[q] = input[j];
			input[j] = t;
			j--;
			q++;
		}


	}
	int nextspace(int j, int len, char input[])
	{
		int p, q = -1;
		for (p = j; p < len; p++)
		{
			if (input[p] == ' ')
			{
				q = p;
				break;
			}
		}
		if (q>0)
		{
			return q;
		}
		else
		{
			return j;
		}




	}
	