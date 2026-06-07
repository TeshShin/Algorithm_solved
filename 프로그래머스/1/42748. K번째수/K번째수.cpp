#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(const vector<int>& command : commands)
    {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        vector<int> newArray;
        for(int n = i - 1; n < j; n++)
        {
            newArray.push_back(array[n]);
        }
        sort(newArray.begin(), newArray.end());
        answer.push_back(newArray[k - 1]);
    }
    return answer;
}