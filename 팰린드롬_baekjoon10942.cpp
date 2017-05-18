#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[2001];
int ans[1000000];
bool flag;
int main()
{
	int N, M;
	int k = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	scanf("%d", &M);
	
	while (M--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		flag = true;
		while (x <= y)
		{
			if (arr[x] != arr[y])
			{
				flag = false; break;
			}
			x++; y--;
		}
		if (flag) ans[k] = 1;
		else ans[k] = 0;
		k++;
	}
	for (int i = 0; i < k; i++) printf("%d\n", ans[i]);
	return 0;
}