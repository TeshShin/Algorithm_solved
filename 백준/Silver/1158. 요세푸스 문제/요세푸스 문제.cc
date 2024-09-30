#include<iostream>

using namespace std;

class Queue {
public:
	Queue() {
		first = -1;
		end = -1;
		maxque = 5001;
		ary = new int[maxque];
	}
	~Queue() {
		delete[] ary;
	}
	void push(int x);
	int pop();
	int size();
	bool empty();


private:
	int maxque;
	int first;
	int end;
	int* ary;
};

void Queue::push(int x) {
	end = (end + 1) % maxque;
	ary[end] = x;
}

int Queue::pop() {
	if (empty()) {
		return -1;
	}
	else {
		first = (first + 1) % maxque;
		return ary[first];
	}
}
int Queue::size() {
	return end - first;
}
bool Queue::empty() {
	return first == end;
}





int main() {
	int N, K;
	Queue q;
	cin >> N >> K;
	cout << "<";
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.pop());
		}
		cout << q.pop();
		if (q.empty()) cout << ">";
		else cout << ", ";
	}

	return 0;
}