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
    int n; cin >> n;
	vector<int> v(n), ans(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	{
		int t; cin >> t; pq.push(t);
		v[0] = t;
	}
	for(int i = 1; i < n; ++i) {
		int c; cin >> c;
		v[i] = c;
		priority_queue<int, vector<int>, greater<int>> h;
		while(!pq.empty()) {
			int t = pq.top(); pq.pop();
			h.push(t + c);
			h.push(t - c);
		}
		pq = h;
		while(!pq.empty() && pq.top() < 0) pq.pop();
	}
	if(sz(pq) > 1) cout << -1;
	else {
		int t = pq.top();
		for(int i = n - 1; i >= 0; --i) {
			ans[i] = t;
			t = abs(v[i] - t);
		}
		for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
	}
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
