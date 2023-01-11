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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
	priority_queue<pll> pq;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		pq.push(pll(t, i));
	}
	while(!pq.empty()) {
		if(sz(pq) == 1) {
			cout << pq.top().ss + 1; return 0;
		}
		auto t1 = pq.top(); pq.pop();
		auto t2 = pq.top(); pq.pop();
		int minn = min(t1.ff, t2.ff);
		t1.ff -= minn;
		if(t1.ff) {
			pq.push(t1);
		}
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
