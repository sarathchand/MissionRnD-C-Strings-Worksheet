  /*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdlib.h>
char KthIndexFromEnd(char *str, int K);
int validate(char *str, int K);

char KthIndexFromEnd(char *str, int K) {
	int p, index;
	p = (validate(str, K));
	if (p == 0)
		return '\0';
	else
	{
		index = p - K - 1;
		return(str[index]);

	}
}
int validate(char *str, int K)
{
	int i, c = 0;
	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			c++;
		}
		if ((K >= c) || (K < 0) || (str == "") || (str == NULL))
		{
			return 0;

		}
		else
		{
			return c;
		}
	}
	else
	{
		return 0;
	}

}