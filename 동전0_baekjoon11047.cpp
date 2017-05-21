#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int arr[10];
int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K == 0) break;
		if (K>=arr[i])
		{
			count = count+(K / arr[i]);
			K = K-(K/arr[i])*arr[i];
		}
	}
	printf("%d\n", count);
	return 0;
}