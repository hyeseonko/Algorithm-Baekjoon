#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int m, n;
	int result[2] = { 0,0 };
	scanf("%d", &m);
	scanf("%d", &n);
	int from = ceil(sqrt(m));   // 올림
	int to = floor(sqrt(n));    // 내림
	if (from > to) puts("-1");
	else {
		result[1] = from*from;
		for (int i = from; i <= to; i++)
		{
			result[0] += i*i;
		}
		printf("%d\n%d\n", result[0], result[1]);
	}
	return 0;
}