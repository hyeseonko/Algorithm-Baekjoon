#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int temp[2];
	int mok1, mok2, smaller;
	scanf("%d %d", &temp[0], &temp[1]);
	if (temp[0] <= temp[1]) smaller = temp[0];
	else smaller = temp[1];
	while (smaller >= 1)
	{
		if (temp[0] % smaller == 0 && temp[1] % smaller == 0)
			{
				mok1 = temp[0] / smaller;
				mok2 = temp[1] / smaller;
				break;
			}
			smaller--;
	}
	printf("%d\n%d\n", smaller, smaller*mok1*mok2);
	return 0;
}