#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main() {
	int test;
	string line;
	
	cin >> test;
	cin.ignore();
	for (int i = 0; i < test; i++) {
		stack<char> word;
		getline(cin, line);
		for (int j = 0; j < line.size(); j++) {
			if (line[j] == ' ') {
				while (!word.empty()) {
					cout << word.top();
					word.pop();
				}
				cout << " ";
			}
			else {
				word.push(line[j]);
			}
		}
		while (!word.empty()) {
			cout << word.top();
			word.pop();
		}
		cout << endl;
	}

	
	

}