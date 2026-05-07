#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(const string& ch : s)
    {
        int count110 = 0;
        int last0idx = -1;
        string result = "";
        for(const char& num : ch)
        {
            result.push_back(num);
            int length = result.length();
            if(length >= 3 && 
               result[length - 3] == '1' &&
               result[length - 2] == '1' &&
               result[length - 1] == '0')
            {
                result.pop_back();
                result.pop_back();
                result.pop_back();
                count110++;
            }
            else if(result[length - 1] == '0')
            {
                last0idx = length - 1;
            }
        }
        string minString = "";
        for(int i = 0; i <= last0idx; i++)
        {
            minString.push_back(result[i]);
        }
        for(int i = 0; i < count110; i++)
        {
            minString += "110";
        }
        for(int i = last0idx + 1; i < result.length(); i++)
        {
            minString.push_back(result[i]);
        }
        answer.push_back(minString);
    }
    return answer;
}