#include<iostream>
#include<queue>
using namespace std;


int N, M;
int knowncnt;

bool known[50];
		//사람, 사람
bool table[51][51];
int party[50][50];
int people[50];
queue<int> q;
int lies = 0;
void bfs()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		known[cur] = 1;
		for (int i = 1; i <= N; i++)
		{
			if (table[cur][i] == 1 && !known[i])
			{
				known[i] = true;
				q.push(i);
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool lie = false;
		for (int j = 0; j < people[i]; j++)
		{
			if (known[party[i][j]])
			{
				lie = true;
				break;
			}
		}
		if (!lie)
			lies++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> knowncnt;
	for (int i = 0; i < knowncnt; i++)
	{
		int num;
		cin >> num;
		known[num] = true;
		q.push(num);
	}
	for (int i = 0; i < M; i++)
	{

		cin >> people[i];
		// 같은 파티에 오는 사람 저장
		for (int j = 0; j < people[i]; j++)
		{
			cin >> party[i][j];
		}
		// 같은 파티에 있는 사람 끼리 간선잇기
		for (int j = 0; j < people[i]; j++)
		{
			for (int k = j + 1; k < people[i]; k++)
			{
				table[party[i][j]][party[i][k]] = true;
				table[party[i][k]][party[i][j]] = true;
			}
		}
	}
	bfs();
	cout << lies;
	return 0;
}