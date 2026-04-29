#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int MakeRepeatNum(int N, int Count)
{
    int Result = 0;
    for(int i = 0; i < Count; i++)
    {
        Result = Result * 10 + N;
    }
    return Result;
}

int solution(int N, int number) {
    vector<unordered_set<int>> DP(9);
    for(int Count = 1; Count <= 8; Count++)
    {
        DP[Count].insert(MakeRepeatNum(N, Count));
        for(int LeftCount = 1; LeftCount < Count; LeftCount++)
        {
            int RightCount = Count - LeftCount;
            for(int LeftValue : DP[LeftCount])
            {
                for(int RightValue : DP[RightCount])
                {
                    DP[Count].insert(LeftValue + RightValue);
                    DP[Count].insert(LeftValue - RightValue);
                    DP[Count].insert(LeftValue * RightValue);
                    if(RightValue != 0)
                        DP[Count].insert(LeftValue / RightValue);
                }
            }
        }
        if(DP[Count].count(number))
        {
            return Count;
        }
    }
    return -1;
}