#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < m; ++j) cin >> v[i][j];
    }
    
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> q;
    // (x, y, col, steps)
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    // (i, j, color)
    
    vis[0][0][0] = true;
    q.push({0, 0, 0, 0});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    auto valid = [&](int i, int j) {
    	return i >= 0 && j >= 0 && i < n && j < m;
    };
    while(!q.empty()) {
    	array<int, 4> _ = q.top(); q.pop();
    	int steps = _[0], x = _[1], y = _[2], col = _[3];
    	
    	if(x == n - 1 && y == n - 1) {
    		cout << steps; return 0;
    	}
    	
    	for(int i = 0; i < 4; ++i) {
    		int nx = x + dx[i], ny = y + dy[i];
    		if(valid(nx, ny)) {
    			if(v[nx][ny] == 0) {
    				// RED
    			}
    			else if(v[nx][ny] == 1) {
    				// PINK
    				// Let it go
    				if(!vis[nx][ny][col]) {
    					vis[nx][ny][col] = true;
    					q.push({steps + 1, nx, ny, col});
    				}
    			}
    			else if(v[nx][ny] == 2) {
    				// ORANGE
    				// MAKE col orange
    				int ncol = 1;
    				if(!vis[nx][ny][ncol]) {
    					vis[nx][ny][ncol] = true;
    					q.push({steps + 1, nx, ny, ncol});
    				}
    			}
    			else if(v[nx][ny] == 3) {
    				// BLUE
    				// Will only pass if col is 1
    				if(col == 1 && !vis[nx][ny][col]) {
    					vis[nx][ny][col] = true;
    					q.push({steps + 1, nx, ny, col});
    				}
    			}
    			else {
    				// Purple
    				int extra = 0;
    				while(valid(nx, ny) && v[nx][ny] == 4) {
    					nx += dx[i], ny += dy[i];
    					++extra;
    				}
    				nx -= dx[i], ny -= dy[i];
    				if(!valid(nx + dx[i], ny + dy[i]) 
    					|| v[nx + dx[i]][ny + dy[i]] == 0
    					|| v[nx + dx[i]][ny + dy[i]] == 3) {
    					// This means we got out of the array while sliding
    					int ncol = 0; // col is reset
    					vis[nx][ny][ncol] = true;
    					q.push({steps + extra, nx, ny, ncol});
    				}
    				else {
    					// It is valid and {1, 2}
    					nx += dx[i], ny += dy[i];
    					int ncol = 0;
    					if(v[nx][ny] == 1) {
    						if(!vis[nx][ny][ncol]) {
    							vis[nx][ny][ncol] = true;
    							q.push({steps + extra + 1, nx, ny, ncol});
    						}
    					}
    					else {
    						assert(v[nx][ny] == 2);
    						int ncol = 1;
    						if(!vis[nx][ny][ncol]) {
    							vis[nx][ny][ncol] = true;
    							q.push({steps + extra + 1, nx, ny, ncol});
    						}
    					}
    				}
    			}
    		}
    	}
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
