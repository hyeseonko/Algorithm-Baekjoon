#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[5];
	int avg = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] < 40) score[i] = 40;
		avg += score[i] / 5;
	}
	printf("%d\n", avg);
	return 0;
}