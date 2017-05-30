/*
	TITLE: KNIGHT MOVES
	BAEKJOON 7562
	TUD CONTEST 2001 #03
	CATEGORY: BFS
	DATE: 2017-05-30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <cstring> // memset

using namespace std;

typedef struct {
	int x;
	int y;
	int moves;
}knight;

queue <knight> q;
bool visited[300][300];
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

int main()
{
	int T; scanf("%d", &T); //Testcase
	while (T--)
	{
		int N; scanf("%d", &N);
		int path[2][2]; // start-end points
		scanf("%d %d", &path[0][0], &path[0][1]);
		scanf("%d %d", &path[1][0], &path[1][1]);

		while (!q.empty()) q.pop(); // q initialization

		q.push({path[0][0], path[0][1], 0});
		visited[path[0][0]][path[0][1]] = true;

		while (!q.empty())
		{
			int front_x = q.front().x;	int front_y = q.front().y;
			int front_moves = q.front().moves;
			
			q.pop();

			if ((front_x == path[1][0]) && (front_y == path[1][1])){
				printf("%d\n", front_moves);
				break;
			}

			for (int i = 0; i < 8; i++){
				int nx = front_x + dx[i];
				int ny = front_y + dy[i];
				if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1 && !visited[nx][ny]) {
					q.push({ nx,ny,front_moves + 1 });
					visited[nx][ny] = true;
				}
			}
		}
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
/* HOW I SOLVED THIS */
/*
	USING BREADTH FIRST SEARCH (QUEUE)
	
	1) 8 Moves simplified by using two arrays[8]
	int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
	int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

	2) Shorten time by set bool visited[300][300]
	When I didn't define 'visited', it took sooooooooooo long time to calculate the result. 
	So, I added visited array and add into queue only if I haven't visited before!

*/