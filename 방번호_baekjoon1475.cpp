/*
	TITLE: ROOM NUMBER
	BAEKJOON 1475
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num[9];
int main()
{
	int N;
	scanf("%d", &N);
	int quotient = N;
	int remainder = 0;
	while (quotient != 0){
		remainder = quotient % 10;
		switch (remainder)
		{
		case 0:
			num[0]++;
			break;
		case 1:
			num[1]++;
			break;
		case 2:
			num[2]++;
			break;
		case 3:
			num[3]++;
			break;
		case 4:
			num[4]++;
			break;
		case 5:
			num[5]++;
			break;
		case 6:
			num[6]++;
			break;
		case 7:
			num[7]++;
			break;
		case 8:
			num[8]++;
			break;
		case 9:
			num[6]++;
			break;
		}
		quotient = quotient / 10;
	}
	num[6] = (num[6] + 1) / 2;
	int set = num[0];
	for (int i = 1; i < 9; i++)	if (num[i] > set) set = num[i];
	printf("%d\n", set);
	return 0;
}