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
	if (num == N - 1)            // �� �� �Ϸ�
	{
		cost += map[by][from];  // ���� ������ ������ ù ������ ��� �߰� finally
		v.push_back(cost);      // ��������� ���Ϳ� ����ֱ�
		return;                 // TSP ��!
	}
	for (int i = 0; i < N; i++)  // ���� �� ���� �ʰ�, ��ȸ ��....
	{
		if (!visited[i] & map[by][i] > 0) // ���� �ѹ��� �湮���� �ʾҰ�, by���� i�� ���� ���� ����Ǿ� ���� ��
		{
			visited[i] = true;                        // i �湮�߽�!
			TSP(from, i, num + 1, cost + map[by][i]); // i���� ���� ���ο� ������ ���� �ٽ� ������
 			visited[i] = false;                       // ��� ������ ���� ������, i�湮���Ѱɷ� �ʱ�ȭ ��Ű��, i++�����ؼ� ���� ��ã�ƺ�. 
		}
	}
}