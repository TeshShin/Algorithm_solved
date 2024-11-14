#include<iostream>
#include<string>
using namespace std;

int str[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, length = 1;
	cin >> N >> M;
	string s;
	cin >> s;

	int count = 0;
    for (int i = 0; i < M; i++) {
        switch (i) {
        case 0:
            str[i] = (s[i] == 'I') ? 1 : -1;
            break;
        case 1:
            str[i] = (s[i] == 'I') ? 1 : -1;
            break;
        default:
            if (s[i] == 'I') {
                if (str[i - 1] == -1 && str[i - 2] > 0) {
                    str[i] = str[i - 2] + 1;
                    if (str[i] > N) {
                        count++;
                    }
                }
                    
                else
                    str[i] = 1;
            }
            else
                str[i] = -1;
            break;
        }
    }
    cout << count;
	return 0;
}