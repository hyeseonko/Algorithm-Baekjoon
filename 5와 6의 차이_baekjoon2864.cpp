/*
	TITLE: DIFFERENCE BETWEEN 5 AND 6
	BAEKJOON 2864
	Contest > Croatian Open Competition in Informatics > COCI 2010/2011 > Contest #3 2
	CATEGORY: MATH
	DATE: 2017-06-20
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int SixToFive(int N)
{
	int i = 1;
	int result = 0;
	while (N != 0)
	{
		if (N % 10 == 6)	result += (5 * i);
		else				result += (N % 10)*i;
		i *= 10;
		N = N / 10;
	}
	return result;
}
int FiveToSix(int N)
{
	int i = 1;
	int result = 0;
	while (N != 0)
	{
		if (N % 10 == 5)	result += (6 * i);
		else				result += (N % 10)*i;
		i *= 10;
		N = N / 10;
	}
	return result;
}
int main()
{
	int A, B; scanf("%d %d", &A, &B);
	printf("%d %d\n", SixToFive(A) + SixToFive(B), FiveToSix(A) + FiveToSix(B));
	return 0;
}