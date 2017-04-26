#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	int x = 0;
	scanf("%d %d", &a, &b);
	while (1)
	{
		if (x > a*(b - 1)) {
			printf("%d\n", x); break;
		}
		x++;
	}
	return 0;
}