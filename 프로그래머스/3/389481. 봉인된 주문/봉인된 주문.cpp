#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// 알파벳 26
ll PowNum(ll digit)
{
    ll times = 1;
    for(ll i = 0; i < digit; i++)
    {
        times *= 26;
    }
    return times;
}
ll StringToNum(const string& s)
{
    ll result = 0;
    ll digit = 0;
    for(ll i = s.length() - 1; i >= 0; i--)
    {
        result += (s[i] - 'a' + 1) * PowNum(digit);
        digit++;
    }
    return result;
}
string NumToString(ll num)
{
    string result = "";
    while(num > 0)
    {
        num--;
        result.push_back('a' + (num % 26));
        num /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}
bool compare(const string& a, const string& b)
{
    if(a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    sort(bans.begin(), bans.end(), compare);
    for(const string& s : bans)
    {
        if(StringToNum(s) <= n)
        {
            n++;
        }
    }
    answer = NumToString(n);
    return answer;
}
