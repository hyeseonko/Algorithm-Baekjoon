#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int map[1001][1001];
int main()
{
	int n, r;
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= 1000; i++)
	{
		map[i][0] = 1; //nC0=1
		map[i][i] = 1; //nCn=1
		for (int j = 1; j <= i-1; j++) // Inner Low Triangle 
		{
			map[i][j] = ((map[i - 1][j]%10007) + (map[i - 1][j - 1]%10007))%10007;
		}
	}
	printf("%d\n", map[n][r]);
	return 0;
}