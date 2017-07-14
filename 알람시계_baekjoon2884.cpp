/*
	TITLE: SPAVANAC
	BAEKJOON 2884
	Contest > Croatian Open Competition in Informatics > COCI 2009/2010 > Contest #7 1¹ø
	CATEGORY: SIMULATION
	DATE: 2017-07-14

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int H, M; scanf("%d %d", &H, &M);
	if (M >= 45) printf("%d %d\n", H, M - 45);
	else
	{
		if (H == 0) H = 24;
		printf("%d %d\n", H - 1, M + 15);
	}
	return 0;
}