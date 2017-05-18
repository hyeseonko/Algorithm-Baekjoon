#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit

int main()
{
	int N, K;
	int arr[1001];
	int count = 0;
	scanf("%d %d", &N, &K);
	for (int i = 2; i <= N; i++) arr[i] = i;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i; j <= N; j += i) {
			if (arr[j] != 0 && arr[j] % i == 0)
			{
				count++;
				if (count == K) { printf("%d\n", arr[j]); exit(-1); }
				arr[j] = 0;
			}
		}
	}
}