/*
	TITLE: THE CASTLE
	BAEKJOON 2234
	IOI 1994 #02
	CATEGORY: BFS
	DATE: 2017-10-11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[50][50];
bool visited[50][50];
bool visited2[2501];
int label[50][50];
queue <pair<int, int>> q;
vector <int> v;
int dx[4] = { 0,-1,0,1};
int dy[4] = { -1,0,1,0 };
int roomsize[2500];
int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	/* 1단계: 라벨링 */
	int room_num = 1;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				q.push({ i,j });
				visited[i][j] = true;
				label[i][j] = room_num;
				roomsize[room_num] = 1;
				while (!q.empty())
				{
					int qx = q.front().first;
					int qy = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int temp = pow(2, k);
						int nx = qx + dx[k];
						int ny = qy + dy[k];
						if ((arr[qx][qy] & temp) == 0 && nx >= 0 && nx < M&&ny >= 0 && ny < N && !visited[nx][ny])
						{
							q.push({ nx,ny });
							visited[nx][ny] = true;
							roomsize[room_num]++;
							label[nx][ny] = room_num;
						}
					}
				}
				room_num++;
			} // room 하나 다 돌기
		}
	} 
	/* 2단계 사이즈 비교 후 합치기 */
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp1 = roomsize[label[i][j]] + roomsize[label[i][j + 1]];
			int temp2 = roomsize[label[i][j]] + roomsize[label[i + 1][j]];
			if (j < N - 1 && label[i][j] != label[i][j + 1]&&!visited2[temp1])		v.push_back(temp1);
			if (i < N - 1 && label[i][j] != label[i + 1][j] && !visited2[temp2])	v.push_back(temp2);
		}
	}
	sort(v.begin(), v.end());
	sort(roomsize + 1, roomsize + room_num + 1);
	printf("%d\n%d\n%d\n", room_num-1, roomsize[room_num], v[v.size() - 1]);
	return 0;
}