#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    for(int n : numbers)
    {
        strings.push_back(to_string(n));
    }
    sort(strings.begin(), strings.end(), [](const string& A, const string& B)
         {
             return A + B > B + A;
         }
         );
    if(strings[0] == "0")
    {
        return "0";
    }
    for(const string& s : strings)
    {
        answer += s;
    }
    return answer;
}