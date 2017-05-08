#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int E, S, M; // Earth, Sun, Moon
	int result = 1;
	scanf("%d %d %d", &E, &S, &M);
	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;
	while (1)
	{
		if (result % 15 == E&&result % 28 == S&&result%19 == M) break;
		result++;
	}
	printf("%d\n", result);
	return 0;
}