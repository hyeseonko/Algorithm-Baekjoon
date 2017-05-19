/*
	TITLE: PRINT IT OUT 10 BY 10
	BAEKJOON 11721
	DATE: 2017-05-19

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i = 0;
	char words[101];
	while (1){
		scanf("%c", &words[i]);
		if (words[i] == '\n') break;
		printf("%c", words[i]);i++;
		if (i % 10 == 0) printf("\n");
	}
	return 0;
}