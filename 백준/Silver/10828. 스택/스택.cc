#include<iostream>

using namespace std;

class Stack {
public:
	Stack() {
		length = 0;
	}
	void push(int x);
	int pop();
	int size();
	bool empty();
	int top();
private:
	int length;
	int ary[10001] = { 0 };
};

void Stack::push(int x)
{
	ary[length] = x;
	length++;
}
int Stack::pop()
{
	if (length == 0) {
		return -1;
	}
	else {
		length--;
		return ary[length];
	}
}
int Stack::size()
{
	return length;
}
bool Stack::empty()
{
	if (length == 0) {
		return true;
	}
	else {
		return false;
	}
}
int Stack::top()
{
	if (length == 0) {
		return -1;
	}
	else {
		return ary[length - 1];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Stack A;
	int length, num;
	string input;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> input;
		if (input == "push")
		{
			cin >> num;
			A.push(num);
		}
		else if (input == "pop")
		{
			cout << A.pop() << '\n';
		}
		else if (input == "size")
		{
			cout << A.size() << '\n';
		}
		else if (input == "empty")
		{
			cout << A.empty() << '\n';
		}
		else if (input == "top")
		{
			cout << A.top() << '\n';
		}
	}


	return 0;
}
