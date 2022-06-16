// N Queens Problem
// Given a N X N grid, you have to place N queens in such a way that no queen cut any other queen
#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> board, int i, int j)
{
    // Checking for same column
    for(int row = 0; row <= i; ++row)
    {
        if(board[row][j] == 1) return false;
    }
    int x = i, y = j;
    // Diagonal towards Right
    while(x >= 0 && y < board[0].size())
    {
        if(board[x][y] == 1) return false;
        ++y, --x;
    }
    x = i, y = j;
    while(x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        --x, --y;
    }
    // This positions seems good
    return true;
}
bool solveNQueen(vector<vector<int>>& board, int i)
{
    // Base Case
    if (i == board.size())
    {
        // Okay, we have made a grid satisfying the above condition
        // Printing the grid now
        for(int row = 0; row < board.size(); ++row)
        {
            for(int column = 0; column < board[0].size(); ++column)
            {
                if (board[row][column] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << "\n";
        }
        cout << "\n\n";
        return false;
    }
    //Recursive Case
    // Try to place queen on some column of the present row.
    for(int j = 0; j < board[0].size(); ++j)
    {
        // This function checks whether the given position is safe for the queen
        if (isSafe(board, i, j))
        {
            // Placing queen on i, j, assuming it to be correct
            board[i][j] = 1;
            bool lets_See = solveNQueen(board, i + 1);
            if (lets_See)
            {
                return true;
            }
            else
            {
                // i, j is not the right position, i.e. Our Assumption is wrong.
                board[i][j] = 0; // Backtrack
            }
        }
    }
    // This means in the current row, there's 0 safe place for queen
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueen(board, 0);
    return 0;
}