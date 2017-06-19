#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int count = 0;
	char input[1000002];
	fgets(input, 1000002, stdin);
	int len = strlen(input);
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
	{
		int chk = input[i];
		if (isalpha(chk)) {
			while (!isspace(chk))
			{
				i++;
				chk = input[i];
			}
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}