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
vector<vector<char>> v;
vector<vector<bool>> vis;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool isValid(int i, int j) {
	if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && v[i][j] == '#') return true;
	return false;
}
int area = 0, peri = 0;
void dfs(int i, int j) {
	vis[i][j] = true;
	++area;
	int to = 0;
	for(int k = 0; k < 4; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if(isValid(ni, nj)) {
			dfs(ni, nj);
		}
	}
	for(int k = 0; k < 4; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if(ni < 0 || ni >= n || nj < 0 || nj >= n || v[ni][nj] == '.') ++to;
	}
	peri += to;
}
// *-> KISS*
int solve() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	cin >> n;
	v.assign(n, vector<char>(n, '.'));
	vis.assign(n, vector<bool>(n, false));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) cin >> v[i][j];
	}
	int maxArea = 0, maxPeri = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(!vis[i][j] && v[i][j] == '#') {
				area = 0, peri = 0;
				dfs(i, j);
				if(area > maxArea) maxArea = area, maxPeri = peri;
				else if(area == maxArea) maxPeri = min(maxPeri, peri);
			}
		}
	}
	cout << maxArea << ' ' << maxPeri;
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
