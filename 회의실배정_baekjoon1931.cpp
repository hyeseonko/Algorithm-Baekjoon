/*
	TITLE: MEETING ROOM SCHEDULE
	BAEKJOON 1931
	CATEOGORY: GREEDY ALGORITHM
	DATE: 2017-08-01
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm> // sort
using namespace std;
vector <pair<int,int>> v;
int main()
{
	int N; scanf("%d", &N);
	while (N--)
	{
		int temp1, temp2; scanf("%d %d", &temp1, &temp2);
		v.push_back({ temp2,temp1 });
	}
	sort(v.begin(), v.end());
	int num = 1;					// the number of meetings 
	int standard = v[0].first;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].second >= standard) // including the same starting point and ending point
		{
			num++;
			standard = v[i].first; // assign a new ending point
		}
	}
	printf("%d\n", num); 	return 0;
}