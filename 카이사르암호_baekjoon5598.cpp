/*
	TITLE: KAISAR CRYPTOGRAPH
	BAEKJOON 5598
	JOI 2007 #03
	DATE: 2017-05-19

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char decode[1001];
	int i = 0;
	while (1)
	{
		scanf("%c", &decode[i]);
		if (decode[i] == '\n') break;
		if (decode[i] <= 67) printf("%c", decode[i] + 23);
		else printf("%c", decode[i] - 3);
		i++;
	}
	return 0;
}