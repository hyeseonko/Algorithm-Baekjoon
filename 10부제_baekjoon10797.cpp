#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int cars = 0;
	int day, carnum;
	scanf("%d", &day);
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &carnum);
		if (carnum == day) cars++;
	}
	printf("%d\n", cars);
	return 0;
}