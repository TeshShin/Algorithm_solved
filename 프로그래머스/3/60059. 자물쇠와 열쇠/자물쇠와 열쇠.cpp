#include <string>
#include <vector>

using namespace std;
// key 회전
vector<vector<int>> Rotate(const vector<vector<int>>& key, int M)
{
    vector<vector<int>> rotated(M, vector<int>(M, 0));

    for (int row = 0; row < M; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            rotated[col][M - 1 - row] = key[row][col];
        }
    }

    return rotated;
}

// 자물쇠와 열쇠가 맞는지
bool IsUnlocked(const vector<vector<int>>& board, int lockOffset, int N)
{
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            if (board[lockOffset + row][lockOffset + col] != 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int M = key.size();
    int N = lock.size();
    // 초기 key의 끝이 lock의 시작
    int lockOffset = M - 1;
    int boardSize = N + lockOffset * 2;

    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    
    // 보드의 중앙인 lock 채우기
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            board[lockOffset + row][lockOffset + col] = lock[row][col];
        }
    }

    for (int rot = 0; rot < 4; ++rot) // 회전 4번
    {
        for (int startRow = 0; startRow <= boardSize - M; ++startRow)
        {
            for (int startCol = 0; startCol <= boardSize - M; ++startCol)
            {
                // 보드에 키 값 더하기
                for (int row = 0; row < M; ++row)
                {
                    for (int col = 0; col < M; ++col)
                    {
                        board[startRow + row][startCol + col] += key[row][col];
                    }
                }
                // lock 부분만 체크하면 됨. lock이 모두 1 이면 가능
                // 0이거나 2가 있으면 불가
                if (IsUnlocked(board, lockOffset, N))
                {
                    return true;
                }
                // 더했던 key 되돌리기
                for (int row = 0; row < M; ++row)
                {
                    for (int col = 0; col < M; ++col)
                    {
                        board[startRow + row][startCol + col] -= key[row][col];
                    }
                }
            }
        }
        // 회전
        key = Rotate(key, M);
    }

    return false;
}