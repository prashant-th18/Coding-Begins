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
    int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	int ind = 0;
	for(int i = 0; i < n; ++i) {
		if(a[0] == b[i]) {
			ind = i; break;
		}
	}
	bool flag = true;
	if(ind == 0) {
		if(a != b) flag = false;
		if(k == 1) flag = false;
		else if(k & 1) {
			if(n == 2) flag = false;
		}
		if(flag) cout << "YES";
		else cout << "NO";
		return 0;
	}
	if(k == 0) {
		cout << "NO"; return 0;
	}
	rotate(b.begin(), b.begin() + ind, b.end());
	if(a == b) {
		if(ind == 1) {
			if(n == 2) {
				if(!(k & 1)) flag = false;
			}
		}
		else {
			// OP
		}
	}
	else {
		flag = false;
	}
	if(flag) cout << "YES";
	else cout << "NO";
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
		#ifdef LOCAL
        	cerr << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
