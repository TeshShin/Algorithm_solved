#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(size_t i = 0; i < phone_book.size() - 1; i++)
    {
        string current = phone_book[i];
        int phoneLen = current.length();
        string other = phone_book[i + 1];
        int otherLen = other.length();
        if(phoneLen >= otherLen) continue;
        bool canFront = true;
        for(int k = 0; k < phoneLen; k++)
        {
            if(current[k] != other[k])
            {
                canFront = false;
                break;
            }
        }
        if(canFront)
        {
            return false;
        }
    }
    return answer;
}