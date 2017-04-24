#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count = 0;
	int testcase;
	int temp[1000];

	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++)
	{
		int test = 0;
		scanf("%d", &temp[i]);
		if (temp[i] == 1) test++;
		for (int j = 2; j <temp[i] ; j++)
		{
			if (temp[i] % j == 0) {
				test++;
				break;
			}
		}
		if (test == 0) count++;
	}
	printf("%d\n", count);
	return 0;
}
