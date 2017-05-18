/*
	TITLE: Kth NUMBER
	BAEKJOON 11004
	DATE: 2017-05-19
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;

int main()
{
	int A, K, temp;
	scanf("%d %d", &A, &K);
	for (int i = 0; i < A; i++){
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[K-1]);
	return 0;
}