#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int sx, sy, tx, ty; // SourceX, SourceY, TargetX, TargetY
    cin >> sx >> sy >> tx >> ty;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    // 1 ... M
    // .
    // .
    // .
    // N
    auto isValid = [&](int x, int y) -> bool
    {
      if(x < 1 || x > n || y < 1 || y > m || vis[x][y]) return false;

      return true;
    };
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    auto bfs = [&](int srcx, int srcy) -> int
    {
        vis[srcx][srcy] = true;
        queue<pair<int, int>> q;
        q.push({srcx, srcy});
        dist[srcx][srcy] = 0;
        while(!q.empty())
        {
            int fx = q.front().first;
            int fy = q.front().second;
            q.pop();
            for(int i = 0; i < 8; ++i)
            {
                int nx = fx + dx[i], ny = fy + dy[i];
                if(isValid(nx, ny))
                {
                    dist[nx][ny] = 1 + dist[fx][fy];
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    if(nx == tx && ny == ty)
                    {
                        return dist[nx][ny];
                    }
                }
            }
        }
        return -1;
    };
    cout << bfs(sx, sy);
    return 0;
}
// You are given a maze of size N X M. You are also given co-ordinates of Knight and co-ordinates of target cell.
// You need to tell the minimum number of steps to go from Knight Cell to target cell.
