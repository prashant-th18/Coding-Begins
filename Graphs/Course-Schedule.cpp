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
    vector<vector<int>> v(n + 1);
    vector<int> in(n + 1);
    for(int i = 0; i < m; ++i) {
    	int a, b; cin >> a >> b;
    	v[a].push_back(b);
    	in[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; ++i) if(in[i] == 0) pq.push(i);
    	
    vector<int> order;
	while(!pq.empty()) {
		int t = pq.top(); pq.pop();
		
		order.push_back(t);
		for(auto val : v[t]) {
			--in[val];
			if(in[val] == 0) pq.push(val);
		}
	}
	for(auto val : order) cout << val << ' ';
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