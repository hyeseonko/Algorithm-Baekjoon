/*
	TITLE: REVERSED ADDITION
	BAEKJOON 1357
	CAEGORY: MATH
	DATE: 2017-07-16
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Rev(int num)
{
	int temp = 0;
	while (num != 0)
	{
		temp = temp * 10 + (num % 10);
		num /= 10;
	}
	return temp;
}

int main()
{
	int X, Y; scanf("%d %d", &X, &Y);
	printf("%d\n", Rev(Rev(X) + Rev(Y)));
	return 0;
}