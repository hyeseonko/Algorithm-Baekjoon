/*
	TITLE: STICK
	BAEKJOON 1094
	CATEGORY: MATH
	DATE: 2017-06-03
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int X; scanf("%d", &X);
	int count = 0;
	if (X == 64) {
		count++;
		X -= 64;
	}
	if (X >= 32&&X<64) {
		count++;
		X -= 32;
	}
	if (X >= 16 && X<32) {
		count++;
		X -= 16;
	}
	if (X >= 8 && X<16) {
		count++;
		X -= 8;
	}
	if (X >= 4 && X<8) {
		count++;
		X -= 4;
	}
	if (X >= 2 && X<4) {
		count++;
		X -= 2;
	}
	if (X == 1) {
		count++;
	}
	printf("%d\n", count);
	return 0;
}