#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll add(ll a, ll b) {
	return (a + b) % MOD;
}
vector<ll> t;
void update(int in, int s, int e, int qs, int qe, ll val) {
	if(qs > qe) return;
	if(s == qs && e == qe) {
		t[in] = add(t[in], val);
		return;
	}

	int mid = (s + e) >> 1;
	update(2 * in, s, mid, qs, min(qe, mid), val);
	update(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, val);
}
ll query(int in, int s, int e, int pos) {
	if(s == e) return t[in];

	int mid = (s + e) >> 1;
	if(pos <= mid) {
		return t[in] + query(2 * in, s, mid, pos);
	}
	else {
		return t[in] + query(2 * in + 1, mid + 1, e, pos);
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i], --v[i];
	t.assign(4 * n, 0);
	vector<ll> dp(n, 0);
	for(int i = n - 1; i >= 0; --i) {
		
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
