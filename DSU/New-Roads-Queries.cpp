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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int, int>> v(m);
	for(int i = 0; i < m; ++i) cin >> v[i].ff >> v[i].ss;
	
	vector<int> par(n + 1, -1);
	vector<int> ans(q, -1);
	vector<unordered_set<int, custom_hash>> li(n + 1);
	
	auto find = [&](int node) {
		vector<int> t;
		while(par[node] > 0) {
			t.push_back(node);
			node = par[node];
		}
		for(auto val : t) par[val] = node;
		return node;
	};
	
	auto unite = [&](int a, int b, int ti) {
		a = find(a), b = find(b);
		
		if(a == b) return;
		
		if(sz(li[a]) > sz(li[b])) swap(a, b);
		
		par[a] = b;
		
		for(auto& val : li[a]) {
			if(li[b].count(val)) {
				ans[val] = ti;
			}
			else li[b].insert(val);
		}
		li[a].clear();
	};
	
	for(int i = 0; i < q; ++i) {
		int a, b; cin >> a >> b;
		if(a == b) ans[i] = 0;
		else {
			li[a].insert(i);
			li[b].insert(i);
		}
	}
	
	for(int i = 0; i < m; ++i) {
		unite(v[i].ff, v[i].ss, i + 1);
	}
	for(auto val : ans) cout << val << '\n';
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
        if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!
