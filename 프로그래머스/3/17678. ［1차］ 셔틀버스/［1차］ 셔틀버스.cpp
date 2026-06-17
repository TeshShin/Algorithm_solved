#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int StringToMin(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}
string MinToString(int min)
{
    int h = min / 60;
    int m = min % 60;
    
    string result;
    if(h < 10)
    {
        result += "0";
    }
    result += to_string(h);
    result += ":";
    if(m < 10)
    {
        result += "0";
    }
    result += to_string(m);
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> minTable;
    string answer = "";
    for(string stringTime : timetable)
    {
        minTable.push_back(StringToMin(stringTime));
    }
    sort(minTable.begin(), minTable.end());
    int tableSize = timetable.size();
    int busTime = 540;
    int index = 0;
    bool canSeat = false;
    while(n--)
    {
        if(n == 0) // 마지막 버스
        {
            for(int i = 0; i < m; i++)
            {
                if(index < tableSize && minTable[index] <= busTime)
                {
                    index++;
                }
                else // m을 다 채우지 못했다면
                {
                    canSeat = true;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < m; i++)
            {
                if(index < tableSize && minTable[index] <= busTime)
                {
                    index++;
                }
                else
                {
                    break;
                }
            }
            busTime += t;
        }
    }
    // 버스에 자리가 남으면 마지막 버스 시간에 가면 됨
    if(canSeat)
    {
        answer = MinToString(busTime);
    }
    else // 버스에 자리가 없다면 마지막으로 탄 사람보다 1분 먼저 타면 됨
    {
        answer = MinToString(minTable[index - 1] - 1);
    }

    return answer;
}