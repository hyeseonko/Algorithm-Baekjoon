#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test[3];

int main()
{
	int command;
	int length = 0;
	scanf("%d", &command);
	test[2] = command;
	do
	{
		test[0] = test[2] / 10; // 십의 자리
		test[1] = test[2] % 10; // 일의 자리
		test[2] = (10 * test[1]) + ((test[0] + test[1]) % 10);
		length++;
	} while (command != test[2]);
	printf("%d\n", length);
	return 0;
}