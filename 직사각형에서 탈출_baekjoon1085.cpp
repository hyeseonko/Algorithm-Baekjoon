#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, w, h;
	int min1, min2 = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (x <= w - x) min1 = x;
	else min1 = w - x;
	
	if (y <= h - y) min2 = y;
	else min2 = h - y;

	if (min1 <= min2) min2 = min1;

	printf("%d\n", min2);
	return 0;
}