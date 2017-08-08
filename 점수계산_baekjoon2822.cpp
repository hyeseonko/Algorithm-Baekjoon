/*
	TITLE: CALCULATE THE SCORE
	BAEKJOON 2822
	CATEGORY: SIMULATION
	DATE: 2017-08-0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++)
	{ 
		scanf("%d", &arr[i]); 
		v.push_back({ arr[i], i + 1 });
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[3].first + v[4].first + v[5].first + v[6].first + v[7].first);
	vector <int> temp;
	for (int i = 3; i < 8; i++) temp.push_back(v[i].second);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < 5; i++) printf("%d ", temp[i]);
	return 0;
}