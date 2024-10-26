#include<iostream>
#include<queue>
using namespace std;

void bfs(int line[], int N, int K) {
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		
		int now = q.front();
		q.pop();
		int moving;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				moving = now - 1;
				if (moving >= 0 && moving < 100001) {
					if (line[moving] == 0) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
					else if(line[moving] > line[now] + 1) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
				}
			}
			else if (i == 1) {
				moving = now + 1;
				if (moving >= 0 && moving < 100001) {
					if (line[moving] == 0) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
					else if (line[moving] > line[now] + 1) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
				}
			}
			else {
				moving = now * 2;
				if (moving >= 0 && moving < 100001) {
					if (line[moving] == 0) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
					else if (line[moving] > line[now] + 1) {
						line[moving] = line[now] + 1;
						q.push(moving);
					}
				}
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	int line[100001] = { 0 };
	if (N == K) {
		cout << 0;
	}
	else {
		bfs(line, N, K);
		cout << line[K];
	}
	return 0;
}