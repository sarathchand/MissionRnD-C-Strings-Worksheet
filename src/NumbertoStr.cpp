/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>


void number_to_str(float number, char *str,int afterdecimal){

	int bp, ap, i, bp1, c = 0, c1 = 0, p, flag = 0;
	float num1 = number;
	bp = (int)number;
	bp1 = bp;
	for (i = 0; i < afterdecimal; i++)
	{
		num1 = num1 * 10;
	}
	ap = (int)num1;
	while (bp1 != 0)
	{
		bp1 = bp1 / 10;
		c++;
	}
	if (num1 < 0)
	{
		flag = 1;
		str[0] = '-';
		bp = bp*-1;
		ap = ap*-1;
	}
	for (i = c + flag - 1; i >= flag; i--)
	{
		p = (bp % 10);
		str[i] = p + '0';
		bp = bp / 10;
	}
	bp1 = ap;
	while (bp1 != 0)
	{
		bp1 = bp1 / 10;
		c1++;
	}
	while (c1 != c)
	{
		p = (ap % 10);
		str[c1 + flag] = p + '0';
		ap = ap / 10;
		c1--;
	}
	if (afterdecimal > 0)
	{
		str[c + flag] = '.';
		str[(c + afterdecimal + flag + 1)] = '\0';
	}
	else
	{
		str[c + flag] = '\0';
	}
	
}
