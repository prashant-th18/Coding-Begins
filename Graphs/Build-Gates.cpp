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

int n;
const int maxx = 4003;
vector<vector<bool>> vis, fence;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
	/* cerr << x << ' ' << y << endl; */
	vis[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < maxx && ny >= 0 && ny < maxx && !vis[nx][ny] && !fence[nx][ny]) dfs(nx, ny);
	}
}
// *-> KISS*
int solve() {
    cin >> n;
	string s; cin >> s;
	vis.assign(maxx, vector<bool>(maxx, false));
	fence = vis;
	int x = 2001, y = 2001;
	vis[x][y] = true; fence[x][y] = true;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'N') {
			y += 2;
			fence[x][y] = fence[x][y - 1] = true;
		}
		else if(s[i] == 'S') {
			y -= 2;
			fence[x][y] = fence[x][y + 1] = true;
		}
		else if(s[i] == 'E') {
			x += 2;
			fence[x][y] = fence[x - 1][y] = true;
		}
		else {
			x -= 2;
			fence[x][y] = fence[x + 1][y] = true;
		}
	}
	cerr << x << ' ' << y << endl;
	int reg = 0;
	for(int i = 0; i < maxx; ++i) {
		for(int j = 0; j < maxx; ++j) {
			if(!vis[i][j] && !fence[i][j]) {
				++reg;
				dfs(i, j);
			}
		}
	}
	cout << reg - 1;
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
