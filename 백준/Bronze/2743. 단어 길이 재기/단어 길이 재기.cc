#include<iostream>
using namespace std;
 
int main() {
	string S; // 문자열
	cin >> S; 
 
	int len = 0;
	for (int i = 0; S[i] ; i++)
	{
		len += 1;
	}
 
	cout << len;
 
	return 0;
}