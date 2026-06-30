#include <string>
#include <vector>

using namespace std;

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

    int lockOffset = M - 1;
    int boardSize = N + lockOffset * 2;

    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            board[lockOffset + row][lockOffset + col] = lock[row][col];
        }
    }

    for (int rot = 0; rot < 4; ++rot)
    {
        for (int startRow = 0; startRow <= boardSize - M; ++startRow)
        {
            for (int startCol = 0; startCol <= boardSize - M; ++startCol)
            {
                for (int row = 0; row < M; ++row)
                {
                    for (int col = 0; col < M; ++col)
                    {
                        board[startRow + row][startCol + col] += key[row][col];
                    }
                }

                if (IsUnlocked(board, lockOffset, N))
                {
                    return true;
                }

                for (int row = 0; row < M; ++row)
                {
                    for (int col = 0; col < M; ++col)
                    {
                        board[startRow + row][startCol + col] -= key[row][col];
                    }
                }
            }
        }

        key = Rotate(key, M);
    }

    return false;
}