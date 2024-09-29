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
	void clear();
private:
	int length;
	int ary[51] = { 0 };
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

void Stack::clear() {
	while (!empty()) {
		pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int length;
	cin >> length;
	Stack stack;
	string name;
	for (int i = 0; i < length; i++)
	{
		stack.clear();
		cin >> name;
		for (int j = 0; j < name.length(); j++)
		{
			if (name[j] == '(')
			{
				stack.push('(');
			}
			else if (name[j] == ')')
			{
				stack.push(')');
			}
		}
		int left = 0, right = 0;
		while (!stack.empty())
		{
			if (right < left) {
				break;
			}
			else {
				if (stack.top() == '(')
				{
					left++;
				}
				else if (stack.top() == ')') {
					right++;
				}
			}
			stack.pop();
		}
		if (right == left) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		//name.clear();
	}
	return 0;
}