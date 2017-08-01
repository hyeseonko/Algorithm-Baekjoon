/*
	TITLE: ROPE
	BAEKJOON 2217
	CATEGORY: GREEDY ALGORITHM
	DATE: 2017-08-02
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
vector <int> ans;
int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp; scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) ans.push_back(v[i] * (N - i));
	sort(ans.begin(), ans.end());
	printf("%d\n", ans[N - 1]);	return 0;
}