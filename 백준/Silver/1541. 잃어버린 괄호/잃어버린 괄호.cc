#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	cin >> input;
	int result = 0;
	string num;
    bool minus = false;
	 for (int i = 0; i <= input.size(); i++) {
        
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (minus) {
                result -= stoi(num);

            }
            else {
                result += stoi(num);
            }
            num = "";
            if (input[i] == '-') {
                minus = true;
            }
        }
        else {
            num += input[i];
        }

    }
    
    cout << result;

	return 0;
}