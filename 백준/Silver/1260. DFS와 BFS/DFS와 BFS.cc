#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 1000;
bool dfsVisited[MAX]; // bool형의 기본 초기화는 0이다.
bool bfsVisited[MAX];


void dfs(vector<vector<bool>>& v, int current) {
	dfsVisited[current] = true;
	cout << current + 1 << " ";

	for (int i = 0; i < v.size(); i++) {
		if (v[current][i] && !dfsVisited[i]) {
			dfs(v, i);
		}
	}
}

void bfs(vector<vector<bool>>& v, int current) {
	queue<int> q;
	bfsVisited[current] = true;
	cout << current + 1 << " ";
	q.push(current);

	while (!q.empty()) {
		current = q.front();
		q.pop();

		for (int i = 0; i < v.size(); i++) {
			if (v[current][i] && !bfsVisited[i]) {
				cout << i + 1 << " ";
				bfsVisited[i] = true;
				q.push(i);
			}
		}
	}

}

int main() {
	int nodenum, edgenum, startnum;
	cin >> nodenum >> edgenum >> startnum;
	startnum--;
	vector<vector<bool>> v(nodenum, vector<bool>(nodenum, 0));

	for (int i = 0; i < edgenum; i++) {
		int start, end;
		cin >> start >> end;
		start--;
		end--;
		v[start][end] = 1;
		v[end][start] = 1;
	}
	dfs(v, startnum); 
	cout << endl;
	bfs(v, startnum);
}