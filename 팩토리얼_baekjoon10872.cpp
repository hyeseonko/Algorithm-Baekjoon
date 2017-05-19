/*
	TITLE: FACTORIAL
	BAEKJOON 10872
	DATE: 2017-05-19

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N;
	int result = 1;
	scanf("%d", &N);
	if (N == 0) printf("0\n");
	else{
		while (N >= 1)
		{
			result *= N;
			N--;
		}
	}
	printf("%d\n", result);
	return 0;	
}