/*
	TITLE: 0 = not cute / 1 = cute
	BAEKJOON 10886
	Contest > kriiicon > kriiICPC #0
	CATEGORY: SIMULATION
	DATE: 2017-06-10

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int N; scanf("%d", &N);
	int sum = 0;
	for(int i=0;i<N;i++)
	{
		int temp; scanf("%d", &temp);
		sum += temp;
	}
	if (sum > N / 2) puts("Junhee is cute!");
	else puts("Junhee is not cute!");
	return 0;
}