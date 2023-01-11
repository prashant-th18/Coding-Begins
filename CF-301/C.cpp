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
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int sr, sc; cin >> sr >> sc;
	int dr, dc; cin >> dr >> dc;
	--sr, --sc, --dr, --dc;
	vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	// [0 .. n - 1][0 .. m - 1][0 .. 1]
	vis[sr][sc][1] = true;
	queue<array<int, 3>> q;
	q.push({sr, sc, 1});
	while(!q.empty()) {
		array<int, 3> t = q.front();
		int x = t[0], y = t[1], cur = t[2];
		if(x == dr && y == dc) {
			
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
