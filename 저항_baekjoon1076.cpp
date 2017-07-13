/*
	TITLE: RESISTANCE
	BAEKJOON 1076
	CATEGORY: MATH
	DATE: 2017-07-13
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp
#include <math.h>   // pow
#define black 0
#define brown 1
#define red 2
#define orange 3
#define yellow 4
#define green 5
#define blue 6
#define violet 7
#define grey 8
#define white 9
char str[7];
long long int sum;

int main()
{
	for (int i = 0; i < 2; i++)
	{
		scanf("%s", str);
		if (!strcmp(str, "black"))	sum = sum * 10 + black;
		else if (!strcmp(str, "brown"))	sum = sum * 10 + brown;
		else if (!strcmp(str, "red"))	sum = sum * 10 + red;
		else if (!strcmp(str, "orange"))	sum = sum * 10 + orange;
		else if (!strcmp(str, "yellow"))	sum = sum * 10 + yellow;
		else if (!strcmp(str, "green"))	sum = sum * 10 + green;
		else if (!strcmp(str, "blue"))	sum = sum * 10 + blue;
		else if (!strcmp(str, "violet"))	sum = sum * 10 + violet;
		else if (!strcmp(str, "grey"))	sum = sum * 10 + grey;
		else if (!strcmp(str, "white"))	sum = sum * 10 + white;
	}
	scanf("%s", str);
	if (!strcmp(str, "black"))	sum *=pow(10,black);
	else if (!strcmp(str, "brown"))	sum *=pow(10, brown);
	else if (!strcmp(str, "red"))	sum *= pow(10, red);
	else if (!strcmp(str, "orange"))	sum *= pow(10, orange);
	else if (!strcmp(str, "yellow"))	sum *= pow(10, yellow);
	else if (!strcmp(str, "green"))	sum *= pow(10, green);
	else if (!strcmp(str, "blue"))	sum *= pow(10, blue);
	else if (!strcmp(str, "violet"))	sum *= pow(10, violet);
	else if (!strcmp(str, "grey"))	sum *= pow(10, grey);
	else if (!strcmp(str, "white"))	sum *= pow(10, white);

	printf("%lld\n", sum);	return 0;
}