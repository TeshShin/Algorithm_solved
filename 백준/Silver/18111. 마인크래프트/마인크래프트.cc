#include<iostream>
#include<vector>
using namespace std;
int N, M, B;

int besttime = 256 * 2 * 500 * 500;
int bestheight = 0;
bool minecraft(vector<vector<int>>& ground, int height, int blocks) {
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 해당 자리가 목표 높이보다 높다면, 해당 블럭 파내기
			if (ground[i][j] > height) {
				time += (ground[i][j] - height) * 2;
				blocks += (ground[i][j] - height);
			}
			// 해당 자리가 목표 높이보다 낮다면, 블럭 쌓기
			else if (ground[i][j] < height) {
				time += (height - ground[i][j]);
				blocks -= (height - ground[i][j]);
			}
		}
	}
	if (blocks < 0) { // 블럭 수가 부족해 더이상 반복할 필요 없는 경우
		return 1;
	}
	else if (time <= besttime) { // 최소 시간과 최대 높이
		besttime = time;
		if (height > bestheight) {
			bestheight = height;
		}
	}
	// 둘다 아니라면 반복문 계속
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> B;

	vector<vector<int>> ground(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
		}
	}
	//브루트포스 알고리즘(무작정 알고리즘)
	for (int i = 0; i <= 256; i++) {
		bool result = minecraft(ground, i, B);
		if (result) {
			break;
		}
	}
	cout << besttime << " " << bestheight;

	return 0;
}