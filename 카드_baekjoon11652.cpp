/*
	TITLE: CARD
	BAEKJOON 11652
	CATEGORY: SORTING
	DATE: 2017-08-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
long long arr[1000000];

int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + N);
	int thebig = 0;
	long long result = arr[0];

	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		while (arr[i] == arr[i - 1])
		{
			temp++;
			i++;
		}
		if (temp > thebig)
		{
			thebig = temp;
			result = arr[i - 1];
		}
	}
	printf("%lld\n", result); return 0;
}