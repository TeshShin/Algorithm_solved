#include<iostream>
#include<string>
using namespace std;



int main() {
	int A = 0, B = 0, C = 0;
	cin >> A >> B >> C;
	cout << A + B - C << endl;
	string afterA = to_string(A);
	string afterB = to_string(B);
	cout << stoi(afterA + afterB) - C;
	return 0;
}