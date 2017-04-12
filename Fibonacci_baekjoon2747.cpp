#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int first, second = 0;
	int result = 1;

	scanf("%d", &num);
	for (int i =1; i < num; i++)
	{
		first = second;
		second = result;
		result = first + second;
	}
	printf("%d\n", result);
	return 0;
}

