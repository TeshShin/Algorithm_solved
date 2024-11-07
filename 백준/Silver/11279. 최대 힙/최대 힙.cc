#include<iostream>

using namespace std;

#define HEAP_SIZE 100001

int countheap = 0;

int heap[HEAP_SIZE];

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void push(int x) {
	heap[++countheap] = x;
	// 비교 스왑
	int child = countheap;
	int parent = child / 2;
	while (countheap > 1 && heap[parent] < heap[child] && parent > 0) { // child가 1이면 parent는 0이 될 수 있어 범위를 벗어나므로
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	if (countheap == 0) {
		return 0;
	}
	int result = heap[1];

	swap(heap[1], heap[countheap--]);

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= countheap) { // root에서 가지가 두 개 있다면
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}
	while (child <= countheap && heap[child] > heap[parent]) {
		swap(heap[child], heap[parent]);

		parent = child;
		child = parent * 2;
		if (child + 1 <= countheap) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0) {

			cout << pop() << '\n';
		}
		else {
			push(x);
		}
	}

	return 0;
}