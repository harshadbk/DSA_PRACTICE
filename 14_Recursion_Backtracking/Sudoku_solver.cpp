#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int rows, int cols, char dig)
{
    for (int j = 0; j < 9; j++)
        if (board[rows][j] == dig)
            return false;

    for (int i = 0; i < 9; i++)
        if (board[i][cols] == dig)
            return false;

    int strow = (rows / 3) * 3;
    int stcol = (cols / 3) * 3;

    for (int i = strow; i < strow + 3; i++)
        for (int j = stcol; j < stcol + 3; j++)
            if (board[i][j] == dig)
                return false;

    return true;
}

bool helper(vector<vector<char>> &board, int rows, int cols)
{
    if (rows == 9)
        return true;

    int nextrow = rows, nextcol = cols + 1;
    if (cols == 8)
    {
        nextcol = 0;
        nextrow = rows + 1;
    }

    if (board[rows][cols] != '.')
        return helper(board, nextrow, nextcol);

    for (char ch = '1'; ch <= '9'; ch++)
    {
        if (isSafe(board, rows, cols, ch))
        {
            board[rows][cols] = ch;
            if (helper(board, nextrow, nextcol))
                return true;
            board[rows][cols] = '.';
        }
    }
    return false;
}

void sudokusolver(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sudokusolver(board);

    for (auto &cols : board)
    {
        for (char c : cols)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}
