/*
	TITLE: FOLDING PAPAERS
	BAEKJOON 1802
	CATEGORY: GREEDY ALGORITHM, RECURSIVE CALL
	DATE: 2017-08-05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[3001];
bool flag;
void check(int s, int e, int l)
{
	int middle = (s + e) / 2;
	if (s == middle || e == middle) return;
	for (int i = 1; i <= l; i++)
	{
		if (str[middle + i] == str[middle - i])
		{
			flag = false;
			return;
		}
	}
	check(s, middle - 1, l / 2);
	check(middle + 1, e, l / 2);
}

int main()
{
	int T; scanf("%d", &T); getchar();
	while (T--)
	{
		scanf("%s", str);
		flag = true;
		int length = strlen(str);
		check(0, length - 1, length / 2);
		if (flag) puts("YES");
		else puts("NO"); 
		memset(str, NULL, sizeof(str));
	}
	return 0;
}