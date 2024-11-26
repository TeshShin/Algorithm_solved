#include<iostream>
#include<list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		list<int> listary;
		string func;
		int n;
		char word;
		cin >> func >> n;
		if (n == 0) {
			cin >> word; // 0일때 [ 받기
		}
		while (n--) {
			int num;
			cin >> word >> num;
			listary.push_back(num);
		}
		cin >> word; // ] 받기
		bool reversed = false;
		bool haserror = false;
		for (int i = 0; i < func.length(); i++) {
			if (func[i] == 'R') {
				reversed = !reversed;
			}
			else {
				if (listary.size() > 0) {
					if (reversed) {
						listary.pop_back();
					}
					else {
						listary.pop_front();
					}
				}
				else {
					haserror = true;
					break;
				}
			}
		}
		if (haserror) {
			cout << "error";
		}
		else {
			cout << '[';
			if (reversed) {
				for (auto i = listary.rbegin(); i != listary.rend(); i++) {
					cout << *i;
					if(i != --listary.rend())
						cout<< ',';
				}
			}
			else {
				for (auto i = listary.begin(); i != listary.end(); i++) {
					cout << *i;
					if (i != --listary.end())
						cout << ',';
				}
			}
			cout << ']';
		}
		cout << '\n';

	}

	
	return 0;
}