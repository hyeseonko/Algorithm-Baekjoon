/*
	TITLE: MINI FANTASY WAR
	BAEKJOON 12790
	Coder's high 2016 Round 1: Online A
	CATEGORY: SIMULATION
	DATE: 2017-08-08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int arr[8];
		for (int i = 0; i < 8; i++) scanf("%d", &arr[i]);
		int sum = 0;
		if (arr[0] + arr[4] < 1) sum += 1;
		else  sum += arr[0] + arr[4];
		if (arr[1] + arr[5] < 1) sum += 5;
		else sum += 5*(arr[1] + arr[5]);
		if (arr[2] + arr[6] > 0) sum += 2 * (arr[2] + arr[6]);
		sum += 2*(arr[3] + arr[7]);
		printf("%d\n", sum);
	}
	return 0;
}