#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	int N[25][2];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N[i][0], &N[i][1]);
	}
	for (int i = 0; i < T; i++)
	{
		printf("%d %d\n", 2 * N[i][1] - N[i][0], N[i][0] - N[i][1]);
	}
	return 0;
}