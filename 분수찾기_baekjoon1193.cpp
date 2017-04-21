#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int i = 1;
	scanf("%d", &num);
	while (1)
	{
		if ((1 + (i*(i - 1) / 2) <= num) && (num < 1 + (i*(i + 1) / 2))) 	break;
		i++;
	}

	if (i % 2 == 0)
	{
		int front = num - (i*(i - 1) / 2);
		int back = (i + 1) - front;
		printf("%d""/""%d\n",front,back);
	}
	else
	{
		int top = i - num +1+(i*(i - 1) / 2);
		int bottom = (i + 1) - top;
		printf("%d""/""%d\n", top,bottom);
	}
	return 0;
}