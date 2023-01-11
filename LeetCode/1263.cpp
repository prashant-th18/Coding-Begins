#define sz(x) ((int)x.size())
#define ff first
#define ss second
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int minPushBox(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        auto valid = [&](int i, int j) -> bool {
            return (i >= 0 && i < n && j >= 0 && j < m && v[i][j] == '.');
        };
        bool vis[n][m][n][m]; // Source, Box
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) for(int k = 0; k < n; ++k) for(int l = 0; l < m; ++l) vis[i][j][k][l] = false;

        queue<array<int, 5>> q;
        pair<int, int> b, s, t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(v[i][j] == 'B') b = pair(i, j);
                else if(v[i][j] == 'S') s = pair(i, j);
                else if(v[i][j] == 'T') t = pair(i, j);
            }
        }
        // Source - x, y .... Box - x, y !
        q.push({s.ff, s.ss, b.ff, b.ss, 0});
        while(!q.empty()) {
            array<int, 5> a = q.front(); q.pop();
            if(a[2] == t.ff && a[3] == t.ss) {
                return a[4];
            }
            vector<vector<bool>> where(n, vector<bool>(m, false));
            // BFS from person location to where it can reach
            queue<pair<int, int>> w;
            where[a[0]][a[1]] = true;
            w.push(pair(a[0], a[1]));
            while(!w.empty()) {
                pair<int, int> f = w.front(); w.pop();
                for(int k = 0; k < 4; ++k) {
                    int ni = f.ff + dx[k], nj = f.ss + dy[k];
                    if(valid(ni, nj) && !where[ni][nj] && !(ni == a[2] && nj == a[3])) {
                        where[ni][nj] = true;
                        w.push(pair(ni, nj));
                    }
                }
            }
            vector<int> h;
            for(int k = 0; k < 4; ++k) {
                int ni = a[2] + dx[k], nj = a[3] + dy[k];
                if(valid(ni, nj) && where[ni][nj]) {
                    h.push_back(k);
                    cout << k << endl;
                }
            }
            for(int i = 0; i < sz(h); ++i) {
                int jk = (h[i] + 2) % 4;
                int ni = a[2] + dx[jk], nj = a[3] + dy[jk];
                int nk = a[2] + dx[h[i]], nl = a[3] + dy[h[i]];
                if(valid(nk, nl) && valid(ni, nj) && !vis[nk][nl][ni][nj]) {
                    vis[nk][nl][ni][nj] = true;
                    q.push({nk, nl, ni, nj, a[4] + 1});
                    cout << ni << ' ' << nj << ' ' << endl << nk << ' ' << nl << endl;
                }
            }
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(where[i][j]) {
                        vis[i][j][a[2]][a[3]] = true;
                    }
                }
            }
        }
        return -1;
    }
};
