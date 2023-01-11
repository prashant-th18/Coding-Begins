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

vector<vector<int>> dp;
vector<bool> vis;
void dfs(int node) {
	vis[node] = true;
	for(const auto& val : dp[node]) {
		if(!vis[val]) {
			dfs(val);
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<pll> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i].ff >> v[i].ss;
	}
	vector<ll> cost(n);
	for(int i = 0; i < n; ++i) {
		cin >> cost[i];
	}
	vector<ll> p(n);
	for(int i = 0; i < n; ++i) cin >> p[i];
	vector<vector<ll>> order;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			// connection between i and j
			ll dis = abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss);
			ll pr = (p[i] + p[j]) * dis;
			vector<ll> t = {pr, i, j};
			order.push_back(t);
		}
		vector<ll> t = {cost[i], i, -1};
		order.push_back(t);
	}
	sort(all(order), [&](vector<ll>& a, vector<ll>& b) {
			return a[0] < b[0];
			});
	vector<int> par(n, -1);
	vector<int> rank(n, 1);
	auto find = [&](int in) {
		vector<int> t;
		while(par[in] > 0) {
			t.push_back(in);
			in = par[in];
		}
		for(auto val : t) par[val] = in;
		return in;
	};
	auto un = [&](int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		if(rank[a] > rank[b]) {
			rank[a] += rank[b];
			par[b] = a;
		}
		else {
			rank[b] += rank[a];
			par[a] = b;
		}
	};
	dp.assign(n + 1, vector<int>());
	vis.assign(n + 1, false);
	
	ll ans = 0;
	vector<int> power;
	vector<pll> connection;
	for(int i = 0; i < sz(order); ++i) {
		ll contri = order[i][0], a = order[i][1], b = order[i][2];
		/* cerr << contri << ' ' << a << ' ' << b << endl; */
		if(b == -1) {
			// Maybe building a power station at "a"
			if(vis[a]) {
				// Power station already there.
				continue;
			}
			else {
				ans += contri;
				dfs(a);
				power.push_back(a);
			}
		}
		else {
			// Want to make a connection between a and b
			if(vis[a] && vis[b]) continue;
			else if(!vis[a] && !vis[b]) {
				if(find(a) != find(b)) {
					ans += contri;
					dp[a].push_back(b); dp[b].push_back(a);
					un(a, b);
					connection.push_back({a, b});
				}
			}
			else {
				// a is not connected to light
				ans += contri;
				dp[a].push_back(b);
				dp[b].push_back(a);
				if(!vis[a]) dfs(a);
				else dfs(b);
				un(a, b);
				connection.push_back({a, b});
			}
		}
	}
	cout << ans << '\n';
	cout << sz(power) << '\n';
	for(auto val : power) cout << val + 1 << ' ';
	cout << '\n' << sz(connection) << '\n';
	for(auto val : connection) cout << val.ff + 1 << ' ' << val.ss + 1 << '\n';
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
