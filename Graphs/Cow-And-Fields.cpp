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
    int n, m, k; cin >> n >> m >> k;
    vector<int> q(k);
    for(int i = 0; i < k; ++i) cin >> q[i];
    	
    vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto fun = [&](int s) {
		vector<int> dist(n + 1, 1e9);
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		vector<bool> vis(n + 1, false);
		vis[s] = true;
		while(!q.empty()) {
			int t = q.front(); q.pop();
			
			for(const auto& val : v[t]) {
				if(!vis[val]) {
					vis[val] = true;
					dist[val] = dist[t] + 1;
					q.push(val);
				}
			}
		}
		return dist;
	};
	
	auto d1 = fun(1);
	auto d2 = fun(n);
	sort(all(q), [&](int a, int b) {
		return d1[a] < d1[b];
	});
	int ans = 0;
	multiset<int, greater<int>> st;
	for(int i = 0; i < k; ++i) {
		st.insert(d2[q[i]]);
	}
	for(int i = 0; i < k - 1; ++i) {
		st.erase(st.lower_bound(d2[q[i]]));
		ans = max(ans, min(d1[q[i]] + 1 + d2[q[i]], d1[q[i]] + *(st.begin()) + 1));
	}
	cout << min(ans, d1[n]);
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