#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*

int32_t main() {
    int n, m, x, y, di, dj; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'A') x = i, y = j;
            if(v[i][j] == 'B') di = i, dj = j;
        }
    }   
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto valid = [&](int i, int j) -> bool
    {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || v[i][j] == '#') return false;
        return true;
    };
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    string res = "URDL";
    unordered_map<char, int> mp;
    mp['U'] = 0; mp['R'] = 1; mp['D'] = 2; mp['L'] = 3;
    vector<vector<int>> dir(n, vector<int>(m, 0));
    auto fun = [&](int i, int j) -> bool
    {
        queue<pair<int, int>> q;
        q.push(pair(i, j));
        vis[i][j] = true;
        while(!q.empty())
        {
            int fx = q.front().first, fy = q.front().second; q.pop();
            if(v[fx][fy] == 'B') return true;
            for(int k = 0; k < 4; ++k)
            {
                int ni = fx + dx[k], nj = fy + dy[k];
                if(valid(ni, nj))
                {
                    dir[ni][nj] = (k + 2) % 4;
                    q.push(pair(ni, nj));
                    vis[ni][nj] = true;
                }
            }
        }
        return false;
    };
    if(fun(x, y))
    {
        cout << "YES\n";
        string ans = "";
        while((di != x) || (dj != y))
        {
            ans += res[(dir[di][dj] + 2) % 4];
            int px = di, py = dj;
            char ch = res[dir[px][py]];
            di += dx[mp[ch]];
            dj += dy[mp[ch]];
        }
        reverse(all(ans));
        cout << sz(ans) << '\n' << ans;
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
// -> Keep It Simple Stupid!
