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
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
    ll x, y, k, m; cin >> x >> y >> k >> m;
	vector<vector<bool>> vis(x + 1, vector<bool>(y + 1, false));
	queue<array<ll, 3>> q;
	q.push({0, 0, 0}); vis[0][0] = true;
	while(!q.empty()) {
		array<ll, 3> f = q.front(); q.pop();
		if(f[2] == k) {
			continue;
		}
		// Fill pail to the top
		if(!vis[f[0]][y]) {
			q.push({f[0], y, f[2] + 1});
			vis[f[0]][y] = true;
		}
		if(!vis[x][f[1]]) {
			q.push({x, f[1], f[2] + 1});
			vis[x][f[1]] = true;
		}
		// 
		// Empty pail
		if(!vis[f[0]][0]) {
			q.push({f[0], 0, f[2] + 1});
			vis[f[0]][0] = true;
		}
		if(!vis[0][f[1]]) {
			q.push({0, f[1], f[2] + 1});
			vis[0][f[1]] = true;
		}
		// 
		// Pour one's content to another
		ll left = x - f[0];
		ll toPour = min(left, f[1]);
		if(!vis[f[0] + toPour][f[1] - toPour]) {
			vis[f[0] + toPour][f[1] - toPour] = true;
			q.push({f[0] + toPour, f[1] - toPour, f[2] + 1});
		}

		left = y - f[1];
		toPour = min(left, f[0]);
		if(!vis[f[0] - toPour][f[1] + toPour]) {
			vis[f[0] - toPour][f[1] + toPour] = true;
			q.push({f[0] - toPour, f[1] + toPour, f[2] + 1});
		}
		//
	}
	int minn = m;
	for(int i = 0; i <= x; ++i) {
		for(int j = 0; j <= y; ++j) {
			if(vis[i][j]) minn = min(minn, (int)abs(m - i - j));
		}
	}
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
