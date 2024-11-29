#include<iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char c; int n;
 
    int T;
    cin >> T;
    while (T--) {
        multiset<int, less<int>> ms; // 오름차순
        int N;
        cin >> N;
        while (N--) {
            cin >> c;
            cin >> n;
            if (c == 'I')
                ms.insert(n);
            else {
                if (n == 1 && !ms.empty())
                    ms.erase(--ms.end());
                else if (n == -1 && !ms.empty())
                    ms.erase(ms.begin());
            }
        }
        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--ms.end()) << " " << *ms.begin() << '\n';
        }
    }
    
    return 0;
}