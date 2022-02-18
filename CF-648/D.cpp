#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int n, m;
vector<vector<char>> v;
vector<vector<bool>> vis;
vector<vector<bool>> reach;
bool valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || v[x][y] == '#') return false;
    return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int i, int j)
{
    reach[i][j] = vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if(valid(ni, nj) && (v[ni][nj] != 'B'))
        {
            dfs(ni, nj);
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        cin >> n >> m;
        v = vector<vector<char>>(n, vector<char>(m, '.'));
        reach = vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            for (int j = 0; j < m && flag; j++) {
                if(v[i][j] == 'B')
                {
                    for (int k = 0; k < 4 && flag; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if(valid(ni, nj) && v[ni][nj] != 'B')
                        {
                            if(v[ni][nj] == 'G') flag = false;
                            else
                            {
                                v[ni][nj] = '#';
                            }
                        }
                    }
                }
            }
        }
        if(v[n - 1][m - 1] == '.' && (flag)) dfs(n - 1, m - 1);
        for (int i = 0; i < n && flag; i++) {
            for (int j = 0; j < m && flag; j++) {
                if(v[i][j]== 'G')
                {
                    flag &= reach[i][j];
                }
            }
        }
        if(flag) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
