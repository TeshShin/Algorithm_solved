#include<iostream>
using namespace std;


struct item {
	int num;
};

class queue {
public:
	queue() {
	 maxQue = 100;
	 front = maxQue - 1;
	 rear = maxQue - 1;
	 item = new int[maxQue];
	}
	~queue() {
		delete[] item;
	}
	bool IsEmpty();
	void enqueue(int num);
	void dequeue(int& num);

private:
	int front, rear;
	int maxQue;
	int* item;
};

bool queue::IsEmpty()
{
	return (rear == front);
}


void queue::enqueue(int num) {
	rear = (rear + 1) % maxQue;
	item[rear] = num;
}

void queue::dequeue(int& num) {
	front = (front + 1) % maxQue;
	num = item[front];
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		queue que;
		int length, index, imt;
		cin >> length >> index;
		for (int j = 0; j < length; j++) {
			cin >> imt;
			que.enqueue(imt);
		}
		int sequence = 1;
		bool found = false;
		while (!found) {
			int first, compare;
			bool canDel = true;
			que.dequeue(first);
			for (int j = 0; j < length - 1; j++) {
				que.dequeue(compare);
				if (first < compare) {
					canDel = false;
				}
				que.enqueue(compare);
			}
			if (canDel) {
				if (index == 0) {
					found = true;
				}
				else {
					sequence++;
				}
				length--;
			}
			else {
				que.enqueue(first);
			}
			index--;
			if (index == -1) {
				index = length - 1;
			}
		}
		cout << sequence << '\n';
	}
}