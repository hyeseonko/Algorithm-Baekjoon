#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[9];
	int sum = 0;
	int j, k;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (j = 0; j < 8; j++)
	{
		for (k = j + 1; k < 9; k++)
		{
			if (arr[j] + arr[k] == (sum - 100)) goto outside;
		}
	}
outside:
	for (int m = 0; m < 9; m++)
	{
		if (m != j && m != k) printf("%d\n", arr[m]);
	}
	return 0;
}