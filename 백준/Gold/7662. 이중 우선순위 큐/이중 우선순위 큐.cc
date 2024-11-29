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
                // 가장 마지막 원소 삭제시-- > --ms.end() 해야함!
                // ms.end()는 가장 마지막 원소 다음 빈곳을 가리키고 있기 때문
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