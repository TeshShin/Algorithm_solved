#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
string MakeBinary(ll num)
{
    string binary = "";
    while(num > 0)
    {
        binary.push_back((num % 2) + '0');
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
bool Check(const string& binary, ll left, ll right)
{
    if (left >= right)
    {
        return true;
    }
    ll mid = left / 2 + right / 2;
    
    if(binary[mid] == '0')
    {
        for(int i = left; i <= right; i++)
        {
            if(binary[i] == '1')
            {
                return false;
            }
        }
    }
    return Check(binary, left, mid - 1) && 
        Check(binary, mid + 1, right);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(ll num : numbers)
    {
        string binary = MakeBinary(num);
        int targetLength = 1;
        while(targetLength < binary.length())
        {
            targetLength = targetLength * 2 + 1;
        }
        ll frontZeroLength = targetLength - binary.length();
        binary = string(frontZeroLength, '0') + binary;
        answer.push_back(Check(binary, 0, targetLength - 1));
    }
    return answer;
}