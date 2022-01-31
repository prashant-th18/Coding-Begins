#include<bits/stdc++.h>
using namespace std;
int N = 1001, M = 1001;
vector<vector<int>> grid(N, vector<int>(M)); // Grid
vector<vector<bool>> vis(N, vector<bool>(M, false)); // Visited Vector
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isValid(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M || vis[x][y] || grid[x][y] == 0) return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        if(isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    // N -> No. of Rows
    // M -> No. of Columns
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cin >> grid[i][j];
        }
    }
    int cc = 0;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(vis[i][j] == false && grid[i][j] == 1)
            {
                ++cc;
                dfs(i, j);
            }
        }
    }
    cout << cc;
    return 0;
}
// You are given a grid which consists of 0 & 1. You can go from any "1" to it's neighbouring "1"
// We have to count number of connected components of these "1" cells.
