#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 8
int N, M;
int input[MAX];
bool visited[MAX] = { 0 };
void solve(int depth, int start);
vector<int> answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N); // 사용법 유의
	solve(0, 0);

	return 0;
}
void solve(int depth, int start) {
	if (depth == M) {
		// 출력
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
	}
	else {
		int temp = -1;
		for (int i = start; i < N; i++) {
			if (temp != input[i]) { // 같은 depth에서 똑같은 숫자를 또 사용하는 것이 아닌지 체크
				//visited[i] = true;
				temp = input[i];
				answer.push_back(input[i]);
				solve(depth + 1, i);
				//visited[i] = false;
				answer.pop_back();
			}

		}
	}


}
