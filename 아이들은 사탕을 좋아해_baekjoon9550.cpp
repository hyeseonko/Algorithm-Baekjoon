#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* 예제 입력 */
	int T, N[100], K[100], temp[100][100];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N[i], &K[i]);
		for (int j = 0; j < N[i]; j++)
		{
			scanf("%d", &temp[i][j]);
		}
	}
	for (int i = 0; i < T; i++) {
		int sum = 0;
		for (int j = 0; j < N[i]; j++)
		{
			sum += (temp[i][j] / K[i]);
		}
		printf("%d\n", sum);
	}
	return 0;
}