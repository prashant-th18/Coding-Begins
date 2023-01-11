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
	freopen("gravity.in", "r", stdin);
	freopen("gravity.out", "w", stdout);
    int n, m; cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m, '.'));
	pair<int, int> start, dest;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if(v[i][j] == 'C') {
				start = {i, j};
			}
			else if(v[i][j] == 'D') {
				dest = {i, j};
			}
		}
	}
	vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	deque<array<int, 4>> q;
	q.push_back({start.ff, start.ss, 0, 0}); // (x, y) dir, steps
	vis[start.ff][start.ss][0] = true;
	// 0 -> down
	// 1 -> up
	int dx[] = {0, 0};
	int dy[] = {1, -1};
	auto valid = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < n && j < m && v[i][j] != '#';
	};
	int minn = 1e9;
	while(!q.empty()) {
		array<int, 4> t = q.front(); q.pop_front();
		if(t[0] == dest.ff && t[1] == dest.ss) {
			minn = min(minn, t[3]);
		}
		if(t[2] == 0) {
			// direction is down
			int ni = t[0] + 1, nj = t[1];
			if(valid(ni, nj) && !vis[ni][nj][0]) {
				vis[ni][nj][0] = true;
				q.push_front({ni, nj, 0, t[3]});
			}
			else if(ni >= n) {
				continue;
				assert(true);
			}
			else {
				if(ni >= 0 && nj >= 0 && ni < n && nj < m && v[ni][nj] == '#') {
					for(int i = 0; i < 2; ++i) {
						ni = t[0] + dx[i], nj = t[1] + dy[i];
						if(valid(ni, nj) && !vis[ni][nj][0]) {
							vis[ni][nj][0] = true;
							q.push_front({ni, nj, 0, t[3]});
						}
					}
				}
				ni = t[0] + 1, nj = t[1];
				if((ni < n && v[ni][nj] == '#') && !vis[t[0]][t[1]][1]) {
					vis[t[0]][t[1]][1] = true;
					q.push_back({t[0], t[1], 1, t[3] + 1});
				}
			}
		}
		else {
			// direction is up
			int ni = t[0] - 1, nj = t[1];
			if(valid(ni, nj) && !vis[ni][nj][1]) {
				vis[ni][nj][1] = true;
				q.push_front({ni, nj, 1, t[3]});
			}
			else if(ni < 0) {
				continue;
			}
			else {
				if(ni >= 0 && nj >= 0 && ni < n && nj < m && v[ni][nj] == '#') {
					for(int i = 0; i < 2; ++i) {
						ni = t[0] + dx[i], nj = t[1] + dy[i];
						if(valid(ni, nj) && !vis[ni][nj][1]) {
							vis[ni][nj][1] = true;
							q.push_front({ni, nj, 1, t[3]});
						}
					}
				}
				ni = t[0] - 1, nj = t[1];
				if((ni >= 0 && v[ni][nj] == '#') && !vis[t[0]][t[1]][0]) {
					vis[t[0]][t[1]][0] = true;
					q.push_back({t[0], t[1], 0, t[3] + 1});
				}
			}
		}
	}
	if(minn == (int)1e9) minn = -1;
	cout << minn;
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
