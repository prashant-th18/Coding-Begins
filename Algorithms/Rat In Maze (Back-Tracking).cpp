// Recursion (Rat in a maze problem)
#include<bits/stdc++.h>
using namespace std;
int cnt = 0; // Total Ways
// I can move only forward or in Down direction
bool ratInMaze(vector<vector<char>> &maze, vector<vector<int>>& soln, int i, int j, int m, int n) // m last row index and n -> last column index
{
    if (i == m && j == n)
    {
        soln[i][j] = 1;
        // I have reached the end!
        // Printing
        for(int rows = 0; rows <= m; ++rows)
        {
            for(int columns = 0; columns <= n; ++columns)
            {
                if(soln[rows][columns] == 1)
                {
                    cout << "1 ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
        cout << endl;
        ++cnt;
        return true;
    }
    // Checking if I am not outside the maze
    if (i > m || j > n)
    {
        return false;
    }
    // Checking for Blocked blocks
    if (maze[i][j] == 'X')
    {
        return false;
    }
    // Assuming this block is present in the solution
    soln[i][j] = 1;
    // Recursive Case

    /* 
    ****If we want all cases to be printed****

    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m , n);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    // Back - Tracking
    soln[i][j] = 0;

    if (rightSuccess || downSuccess)
    {
        return true;
    }
    return false;
    */

    // **** If we want any case that satisfies our condition****
    if(ratInMaze(maze, soln, i, j + 1, m , n) || ratInMaze(maze, soln, i + 1, j, m, n))
    {
        // Back - Track Step
        soln[i][j] = 0;
        return true;
    }
    soln[i][j] = 0;
    return false;
}
int main()
{
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> maze(rows, vector<char>(columns, '.'));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> soln(rows, vector<int>(columns, 0));
    bool ans = ratInMaze(maze, soln, 0, 0, rows - 1, columns - 1);
    cout << cnt << endl;
    if(!ans)
    {
        cout << "Maze doesn't exist!";
    }
    return 0;
}