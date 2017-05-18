/*
	TITLE: PUZ
	BAEKJOON 2869
	COCI 2010/2011 CONTEST #2-1
	DATE: 2017-05-18

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int cur=0, day=0;
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	while (cur < V)
	{
		day++;
		cur += A;
		if (cur == V) break;
		cur -= B;
	}
	printf("%d\n", day);
	return 0;
}