#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int A;
	unsigned int result = 1;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &A);
		result *= A;
	}
	printf("%d\n", result);
	while (result != 0)
	{
		int remainder = result % 10;
		result /= 10;
		switch (remainder)
		{
		case 0:
			num[0]++; break;
		case 1:
			num[1]++; break;
		case 2:
			num[2]++; break;
		case 3:
			num[3]++; break;
		case 4:
			num[4]++; break;
		case 5:
			num[5]++; break;
		case 6:
			num[6]++; break;
		case 7:
			num[7]++; break;
		case 8:
			num[8]++; break;
		case 9:
			num[9]++; break;
		}
	}
	for (int i = 0; i < 10; i++)	printf("%d\n", num[i]);
	return 0;
}