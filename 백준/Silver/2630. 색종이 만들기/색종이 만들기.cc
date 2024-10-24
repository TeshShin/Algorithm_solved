#include<iostream>
#include<vector>
using namespace std;

int whitenblue[2]; // 0 : 흰, 1 : 블루

void cutting(vector<vector<int>>& box, int x, int y, int size) {
	if (size == 1) {
		whitenblue[box[x][y]]++;
		return;
	}
	int save = box[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (save != box[i][j]) {
				save = -1;
				break;
			}
		}
	}
	if (save == -1) {
		cutting(box, x, y, size / 2);
		cutting(box, x+size / 2, y, size / 2);
		cutting(box, x, y+size / 2, size / 2);
		cutting(box, x+size / 2, y+size / 2, size / 2);
	}
	else {
		whitenblue[save]++;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int>> box(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[i][j];
		}
	}
	cutting(box, 0, 0, N);
	cout << whitenblue[0] << '\n' << whitenblue[1];
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << box[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	return 0;
}