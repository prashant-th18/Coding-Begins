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

const int N = 3e5;
int n, height = 1, myNode = -1;
vector<vector<int>> v, t;
vector<int> value, visOrder;
vector<vector<int>> primes;
vector<bool> vis;
vector<int> spf;
void init() {
	spf.assign(N + 1, -1);
	for(int i = 2; i < N; i += 2) spf[i] = 2;
	for(int i = 3; i < N; i += 2) {
		if(spf[i] == -1) {
			for(int j = i; j < N; j += 2 * i) {
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
}
void dfs(int node, int h) {
	vis[node] = true;
	visOrder.push_back(node);
	if(h > height) {
		height = h;
		myNode = node;
	}
	for(auto& val : t[node]) {
		if(!vis[val]) {
			dfs(val, h + 1);
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n;
	v.assign(n + 1, vector<int>());
	t.assign(n + 1, vector<int>());
	value.assign(n + 1, 0);
	primes.assign(N + 1, vector<int>());
	vis.assign(n + 1, false);
	for(int i = 0; i < n; ++i) cin >> value[i + 1];
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		int val = value[i];
		while(spf[val] != -1) {
			int num = spf[val];
			primes[num].push_back(i);
			while(val % num == 0) val /= num;
		}
	}
	int maxx = 0;
	for(int i = 2; i < N; ++i) {
		if(spf[i] != i) continue;
		/* cout << i << endl; */
		vector<int> order;
		for(auto& val : primes[i]) {
			maxx = max(maxx, 1);
			order.push_back(val);
			for(const auto& node : v[val]) {
				if(value[node] % i == 0) {
					t[val].push_back(node);
				}
			}
		}
		for(auto& val : order) {
			if(!vis[val]) {
				height = 0;
				myNode = val;
				dfs(val, 1);
				for(auto& vall : visOrder) vis[vall] = false;
				visOrder.clear();
				dfs(myNode, 1);
				maxx = max(maxx, height);
				visOrder.clear();
			}
		}
		for(auto& val : order) vis[val] = false, t[val].clear();
	}
	cout << maxx;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	init();
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
