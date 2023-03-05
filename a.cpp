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

const int mx = (int)1e5 + 10;
// *-> KISS*
int solve() {
	int n; cin >> n;
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		pq.push({b, a});
	}
	int curr = INT_MAX;
	while(!pq.empty()) {
		pair<int, int> p = pq.top(); pq.pop();
		curr = min(curr, p.ff);
		curr -= p.ss;
		if(curr < 0) {
			cout << "No"; return 0;
		}
	}
	cout << "Yes";
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
