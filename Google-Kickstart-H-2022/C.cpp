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

int n, maxx = 1, cnt;
vector<int> value;
vector<vector<int>> v;
vector<int> in;
void dfs(int node, int par) {
	++cnt;
	for(int& val : v[node]) {
		if(val != par) {
			dfs(val, node);
		}
	}
}
// *-> KISS*
int solve() {
    cin >> n;
    value.assign(n + 1, 0);
    v.assign(n + 1, vector<int>());
    in.assign(n + 1, 0);
    for(int i = 0; i < n; ++i) {
    	cin >> value[i + 1];
    }
    for(int i = 0; i < n - 1; ++i) {
    	int a, b; cin >> a >> b;
    	if(value[a] < value[b]) {
    		in[a]++;
    		v[b].push_back(a);
    	}
    	else if(value[b] < value[a]) {
    		in[b]++;
    		v[a].push_back(b);
    	}
    }
    maxx = 1;
    for(int i = 1; i <= n; ++i) {
    	if(in[i] == 0) {
    		cnt = 0;
    		dfs(i, -1);
    		maxx = max(maxx, cnt);
    	}
    }
    cout << maxx;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
    	cout << "Case #" << i << ": ";
		// #ifdef LOCAL
        // 	cout << "##################" << '\n';
		// #endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	// #ifdef LOCAL
    // 	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	// #endif
	return 0;
}
// -> Keep It Simple Stupid!
