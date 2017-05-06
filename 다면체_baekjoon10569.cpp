#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	int temp[100][2];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &temp[i][0], &temp[i][1]);
	}
	for (int i = 0; i < T; i++)
	{
		printf("%d\n", 2 + temp[i][1] - temp[i][0]);
	}
	return 0;
}