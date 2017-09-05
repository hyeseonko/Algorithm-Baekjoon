#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[500001], bottom[500000], top[500000];


int SecondSmallest(int start, int end, int target)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] < target) start = mid + 1;
		else end = mid;
	}
	return end-1;
}

int main()
{
	int N, H; scanf("%d %d", &N, &H);
	arr[1]=arr[H] = N / 2;

	for (int i = 1; i <= N; i++)
	{
		int length;	scanf("%d", &length);
		if (length == 1) continue;
		if (i % 2 == 1)	bottom[length]++;
		else top[length]++;
	}
	for (int i = (H - 2); i >= 2; i--)
	{
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];
	}
	for (int i = 2; i <= (H - 1); i++)
	{
		arr[i] = bottom[i]+top[H - i + 1];
	}
	sort(arr + 1, arr + H + 1);
	printf("%d %d\n", arr[1], SecondSmallest(1, H, arr[1]+1));
	return 0;
}