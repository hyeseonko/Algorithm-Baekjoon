/*
	TITLE: RECEIPT
	BAEKJOON 5565
	CATEGORY: SIMULATION
	DATE: 2017-06-10

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int T; scanf("%d", &T);
	for (int i = 0; i < 9; i++)
	{
		int temp; scanf("%d", &temp);
		T -= temp;
	}
	printf("%d\n", T); return 0;
}