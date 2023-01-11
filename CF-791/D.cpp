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

ll n, m, k;
vector<ll> value;
vector<vector<ll>> v;
vector<int> vis, c;
vector<pll> edges;
bool dfs(int node, ll len) {
	c.push_back(node);
	if(len == k) return true;
	vis[node] = 1;
	for(const auto& val : v[node]) {
		if(vis[val] == 1) {
			return true;
		}
		else if(vis[val] == 2) continue;
		else {
			if(dfs(val, len + 1)) return true;
		}
	}
	vis[node] = 2;
	return false;
}
// *-> KISS*
int solve() {
    cin >> n >> m >> k;
	v.assign(n + 1, vector<ll>());
	vis.assign(n + 1, 0);
	value.assign(n + 1, 0);
	edges.assign(m, {0, 0});
	for(int i = 1; i <= n; ++i) {
		cin >> value[i];
	}
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		edges[i] = pair(a, b);
	}
	vector<pll> p(n);
	for(int i = 0; i < n; ++i) {
		p[i] = pair(value[i + 1], i + 1);
	}
	sort(p.begin(), p.end());
	int s = 0, e = n - 1, ans = -1;
	while(s <= e) {
		int mid = (s + e) >> 1;
		vector<bool> here(n + 1, false);
		for(int i = 0; i <= mid; ++i) {
			here[p[i].ss] = true;
		}
		v.assign(n + 1, vector<ll>());
		vis.assign(n + 1, 0);
		vector<int> in(n + 1, 0);
		for(int i = 0; i < m; ++i) {
			if(here[edges[i].ff] && here[edges[i].ss]) {
				v[edges[i].ff].push_back(edges[i].ss);
				in[edges[i].ss]++;
			}
		}
		bool flag = false;
		for(int i = 1; i <= n && (!flag); ++i) {
			if(vis[i] == 0) {
				c.clear();
				if(dfs(i, 1)) {
					flag = true;
				}
				else {
					ll maxx = -1;
					queue<pll> q;
					for(auto val : c) {
						if(in[val] == 0) q.push(pair(val, 0));
					}
					while(!q.empty()) {
						ll node = q.front().ff, dis = q.front().ss; q.pop();
						maxx = max(maxx, dis);
						for(auto& val : v[node]) {
							--in[val];
							if(in[val] == 0) q.push(pll(val, dis + 1));
						}
					}
					if(maxx >= k - 1) flag = true; 
				}
			}
		}
		if(flag) {
			ans = p[mid].ff;
			e = mid - 1;
		}
		else s = mid + 1;
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
