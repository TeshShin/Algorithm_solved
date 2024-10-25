#include<iostream>
#include<vector>
using namespace std;
int N;
int visit = 0;
int Z(int row, int col, int size) {
	if (size == 1) return 0;
	int piece = (size * size) / 4;
	if (row < size / 2) {
		if (col < size / 2) {
			return Z(row, col, size / 2);
		}
		else {
			return Z(row, col - size / 2, size / 2) + piece;
		}
	}
	else {
		if (col < size / 2) {
			return Z(row - size / 2, col, size / 2) + piece * 2;
		}
		else {
			return Z(row - size / 2, col - size / 2, size / 2) + piece * 3;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int row, col;
	cin >> N >> row >> col;
	int size = 1;
	for (int i = 0; i < N; i++) {
		size *= 2;
	}
	cout << Z(row, col, size);
}