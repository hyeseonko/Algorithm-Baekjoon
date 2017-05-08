#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <vector>    // vector
#include <algorithm> // sort

using namespace std;
int N;
int map[10][10];
bool visited[10];   
vector <int> v;
void TSP(int from, int by, int num, int cost);     // TSP function

int main()
{
	/* INPUT */
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	/* FUNCTION */
	for (int i = 0; i < N; i++)
	{
		visited[i] = true;
		TSP(i, i, 0, 0);
		visited[i] = false;
	}

	/* OUTPUT */
	sort(v.begin(), v.end());
	printf("%d\n", v.front());
	return 0;
}

void TSP(int from, int by, int num, int cost)    // TSP function
{
	if (num == N - 1)            // 한 턴 완료
	{
		cost += map[by][from];  // 제일 마지막 지점과 첫 지점의 비용 추가 finally
		v.push_back(cost);      // 최종비용을 벡터에 집어넣기
		return;                 // TSP 끝!
	}
	for (int i = 0; i < N; i++)  // 아직 다 돌지 않고, 순회 중....
	{
		if (!visited[i] & map[by][i] > 0) // 아직 한번도 방문하지 않았고, by에서 i로 가는 길이 연결되어 있을 때
		{
			visited[i] = true;                        // i 방문했슈!
			TSP(from, i, num + 1, cost + map[by][i]); // i에서 이제 새로운 지점을 향해 다시 재귀출발
 			visited[i] = false;                       // 재귀 끝내고 새로 왔으니, i방문안한걸로 초기화 시키고, i++증가해서 새로 길찾아봐. 
		}
	}
}