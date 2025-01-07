#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

void bfs(int a) {
	q.push(a);



}


int A, B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	int cnt = 1;
	while (true) {
		if (B == A) {
			break;
		}
		else if (B < A) {
			cnt = -1;
			break;
		}
		else if (B % 2 == 0) {
			B /= 2;
		}
		else if (B % 10 == 1) {
			B /= 10;
		}
		else {
			cnt = -1;
			break;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}