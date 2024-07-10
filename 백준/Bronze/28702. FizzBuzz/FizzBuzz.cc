#include<iostream>
#include<string>
using namespace std;



int main() {
	string input[3];
	cin >> input[0]
		>> input[1]
		>> input[2];
	if (input[0][0] != 'F' && input[0][0] != 'B') {
		if (!((stoi(input[0]) + 3) % 15)) {
			cout << "FizzBuzz";
		}
		else if (!((stoi(input[0]) + 3) % 3)) {
			cout << "Fizz";
		}
		else if (!((stoi(input[0]) + 3) % 5)) {
			cout << "Buzz";
		}
		else {
			cout << stoi(input[0]) + 3;
		}
	}
	else if (input[1][0] != 'F' && input[1][0] != 'B') {
		if (!((stoi(input[1]) + 2) % 15)) {
			cout << "FizzBuzz";
		}
		else if (!((stoi(input[1]) + 2) % 3)) {
			cout << "Fizz";
		}
		else if (!((stoi(input[1]) + 2) % 5)) {
			cout << "Buzz";
		}
		else {
			cout << stoi(input[1]) + 2;
		}
	}
	else if (input[2][0] != 'F' && input[2][0] != 'B') {
		if (!((stoi(input[2]) + 1) % 15)) {
			cout << "FizzBuzz";
		}
		else if (!((stoi(input[2]) + 1) % 3)) {
			cout << "Fizz";
		}
		else if (!((stoi(input[2]) + 1) % 5)) {
			cout << "Buzz";
		}
		else {
			cout << stoi(input[2]) + 1;
		}
	}
	return 0;
}