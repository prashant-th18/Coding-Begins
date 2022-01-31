#include<bits/stdc++.h>
using namespace std;
int N = 1001, M = 1001;
vector<vector<bool>> vis(N, vector<bool>(M, false));
vector<vector<int>> dist(N, vector<int>(M, 0));
bool isValid(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M || vis[x][y]) return false;
    
    return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int srcx, int srcy)
{
    queue<pair<int, int>> q;
    q.push({srcx, srcy});
    dist[srcx][srcy] = 0;
    vis[srcx][srcy] = true;
    while(!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = fx + dx[i];
            int newY = fy + dy[i];
            if(isValid(newX, newY))
            {
                dist[newX][newY] = 1 + dist[fx][fy];
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    cout << "Distance Array\n";
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    cin >> N >> M;
    int x, y; cin >> x >> y;
    bfs(x, y);
    return 0;
}
