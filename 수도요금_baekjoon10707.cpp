/*
	TITLE: WATER BILL
	BAEKJOON 10707
	Olympiad > JOI 2015 ¿¹¼± 1¹ø
	CATEGORY: SIMULATION
	DATE: 2017-07-14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A, B, C, D, P;
	scanf("%d", &A);	scanf("%d", &B);	scanf("%d", &C);	scanf("%d", &D);   scanf("%d", &P);
	if (P <= C)
	{
		if (A*P > B) printf("%d\n", B);
		else printf("%d\n", A*P);
	}
	else
	{
		if (A*P > B + (P - C)*D) printf("%d\n", B + (P - C)*D);
		else printf("%d\n", A*P);
	}
	return 0;
}