#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Sorting(int test[], int len)
{
	for (int m = 0; m < len - 1; m++)
	{
		for (int n = m + 1; n < len; n++)
		{
			if (test[m] > test[n]) {
				int buffer = test[n];
				test[n] = test[m];
				test[m] = buffer;
			}
		}
	}
}

int main()
{
	int num;
	int temp[50];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp[i]);
	}
	Sorting(temp, num);
	printf("%d\n", temp[0] * temp[num - 1]);
	return 0;
}

