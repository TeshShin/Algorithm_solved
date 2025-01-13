#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    double res;
    if (s[0] == 'A') res = 4;
    else if (s[0] == 'B') res = 3;
    else if (s[0] == 'C') res = 2;
    else if (s[0] == 'D') res = 1;
    else res = 0;

    if (s[1] == '+') res += 0.3;
    else if (s[1] == '-') res -= 0.3;

    printf("%.1f", res);
    return 0;
}