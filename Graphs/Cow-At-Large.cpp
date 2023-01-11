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
using pll = pair<ll, ll>;

// *-> KISS*
int solve() {
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
    int n, k; cin >> n >> k;
	vector<bool> vis1(n + 1, false), vis2(n + 1, false);
	vector<vector<int>> v(n + 1);
	vector<int> in(n + 1, 0);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		in[a]++;
		in[b]++;
	}
	queue<pll> q;
	for (int i = 1; i <= n; ++i) {
		if(in[i] == 1) q.push({i, 2}), vis2[i] = true;
	}
	q.push({k, 1}); vis1[k] = true;
	int ans = 0;
	while(!q.empty()) {
		pll p = q.front(); q.pop();
		int node = p.ff;
		if(p.ss == 1) {
			for(int& val : v[node]) {
				if(vis1[val]) continue;
				else if(vis2[val]) ++ans;
				else {
					vis1[val] = true;
					q.push({val, 1});
				}
			}
		}
		else {
			for(int& val : v[node]) {
				if(vis2[val] || vis1[val]) continue;
				else {
					vis2[val] = true;
					q.push({val, 2});
				}
			}
		}
	}
	cout << ans;
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
