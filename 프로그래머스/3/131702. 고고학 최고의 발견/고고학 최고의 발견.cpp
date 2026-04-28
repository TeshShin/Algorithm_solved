#include <string>
#include <vector>

using namespace std;

int DRow[4] = {1, -1, 0, 0};
int DCol[4] = {0, 0, 1, -1};
bool IsSolved(const vector<vector<int>>& clockHands)
{
    for(const int Time : clockHands[clockHands.size() - 1])
    {
        if(Time != 0)
        {
            return false;
        }
    }
    return true;
}
bool CanGo(int Row, int Col, int Size)
{
    return Row >= 0 && Col >= 0 && Row < Size && Col < Size;
}

void ControlClock(vector<vector<int>>& clockHands, int Row, int Col, int ControlCounts)
{
    clockHands[Row][Col] = (clockHands[Row][Col] + ControlCounts) % 4;
    for(int i = 0; i < 4; i++)
    {
        int NewRow = Row + DRow[i];
        int NewCol = Col + DCol[i];
        if(CanGo(NewRow, NewCol, clockHands.size()))
        {
            clockHands[NewRow][NewCol] = (clockHands[NewRow][NewCol] + ControlCounts) % 4;
        }
    }
}


int solution(vector<vector<int>> clockHands) {
    int answer = 1e6;
    int N = clockHands.size();
    // 00 -> (1~4) 0 1 2 3 으로 돌린 횟수
    for(int Case = 0; Case < (1 << (2 * N)); Case++)
    {
        int TotalCount = 0;
        vector<vector<int>> Copy = clockHands;
        int Temp = Case;
        for(int Col = 0; Col < N; Col++)
        {
            int PressCount = Temp % 4;
            Temp /= 4; // 맨 우측 버리고 땡김
            TotalCount += PressCount;
            ControlClock(Copy, 0, Col, PressCount);
        }
        
        for(int Row = 0; Row < N - 1; Row++)
        {
            for(int Col = 0; Col < N; Col++)
            {
                int Time = Copy[Row][Col];
                if(Time != 0)
                {
                    int PressCount = 4 - Time;
                    ControlClock(Copy, Row + 1, Col, PressCount);
                    TotalCount += PressCount;
                }
            }
        }
        if(IsSolved(Copy))
        {
            answer = min(answer, TotalCount);
        }
    }

    return answer;
}