#include<iostream>
#include<vector>
using namespace std;


int N, M; // 4<= N, M <=500

// 짤리는 녀석들은 우선은 제외시키지 않고 생각한다.
int tetromino(vector<vector<int>>& matrix) {
	int maxtotal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// l 가로
			if (j < M - 3) {
				int k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i][j + 3];
				maxtotal = (maxtotal > k) ? maxtotal : k;
			}
			// l 세로
			if (i < N - 3) {
				int k = matrix[i][j] + matrix[i+1][j] + matrix[i+2][j] + matrix[i+3][j];
				maxtotal = (maxtotal > k) ? maxtotal : k;
			}
			// L 가로
			if (j < M - 2) {
				if (i > 0) { // 위 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i - 1][j + 2];
					maxtotal = (maxtotal > k) ? maxtotal : k;
					k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i - 1][j];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (i < N - 1) { // 아래 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 2];
					maxtotal = (maxtotal > k) ? maxtotal : k;
					k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// L 세로
			if (i < N - 2) {
				if (j > 0) { // 왼 뾰쪽
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 2][j - 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
					k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i][j - 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (j < M - 1) { // 오른 뾰족
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 2][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
					k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// T 가로
			if (j < M - 2) {
				if (i > 0) { // 위 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i - 1][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (i < N - 1) { // 아래 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// T 세로
			if (i < N - 2) {
				if (j > 0) { // 왼 뾰쪽
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 1][j - 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (j < M - 1) { // 오른 뾰족
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 1][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// S 가로
			if (j < M - 2) {
				if (i > 0) { // 위 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i - 1][j + 1] + matrix[i - 1][j + 2];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (i < N - 1) { // 아래 뾰족
					int k = matrix[i][j] + matrix[i][j + 1] + matrix[i+1][j + 1] + matrix[i + 1][j + 2];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// S 세로
			if (i < N - 2) {
				if (j > 0) { // 왼 뾰쪽
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j - 1] + matrix[i + 1][j - 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
				if (j < M - 1) { // 오른 뾰족
					int k = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j + 1] + matrix[i + 1][j + 1];
					maxtotal = (maxtotal > k) ? maxtotal : k;
				}
			}
			// 네모
			if (i < N - 1 && j < M - 1) {
				int k = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1];
				maxtotal = (maxtotal > k) ? maxtotal : k;
			}
		}
	}
	return maxtotal;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;


	vector<vector<int>> matrix(N, vector<int>(M, 0));

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << tetromino(matrix);

	return 0;
}