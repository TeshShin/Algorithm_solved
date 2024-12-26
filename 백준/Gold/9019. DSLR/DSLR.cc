#include<iostream>
#include<queue>
using namespace std;

int D(int n);
int S(int n);
int L(int n);
int R(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		bool visited[10000] = { 0 };
		visited[A] = true;
		queue<pair<int, string>> q;
		q.push({ A, "" });
		while (!q.empty()) {
			int num = q.front().first;
			string str = q.front().second;
			q.pop();
			if (num == B) {
				cout << str << '\n';
				break;
			}
			int visit = D(num);
			if (!visited[visit]) {
				q.push({ visit, str + "D" });
				visited[visit] = true;
			}
			visit = S(num);
			if (!visited[visit]) {
				q.push({ visit, str + "S" });
				visited[visit] = true;
			}
			visit = L(num);
			if (!visited[visit]) {
				q.push({ visit, str + "L" });
				visited[visit] = true;
			}
			visit = R(num);
			if (!visited[visit]) {
				q.push({ visit, str + "R" });
				visited[visit] = true;
			}
		}

	}
	return 0;
}

int D(int n) {
	return (2 * n) % 10000;
}
int S(int n) {
	return (n == 0) ? 9999 : n - 1;
}
int L(int n) {
	int l = n / 1000;
	int rem = n % 1000;
	return rem * 10 + l;
}
int R(int n) {
	int r = n % 10;
	int rem = (n / 10);
	return r * 1000 + rem;
}