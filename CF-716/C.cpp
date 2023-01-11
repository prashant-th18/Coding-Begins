#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<bool> vis(n, true);
	// Suppose that the product of all of the numbers present in the sequence is p.
	// Now, we know that product % n is equal to 1 iff 
	// p = n * m + 1;
	// We also know that, 
	// if the above equation is satisfied, then
	// gcd(p, n) == gcd(n, 1)
	// Since RHS = 1 
	// => gcd(p, n) = 1, which means that, p and "n" must be co-prime
	// But how it is possible?
	// iff p doesn't contain any number which isn't coprime with n.
	for(int i = 1; i <= n - 1; ++i) {
		if(gcd(i, n) != 1) vis[i] = false;
	}
	int p = 1;
	for(int i = 1; i < n; ++i) {
		if(vis[i]) p = 1LL * p * i % (ll)n;
	}
	if(p != 1) {
		// This means there exists a co-prime number in our new sequence, because of which p != 1.
		// Therefore, we remove it.
		vis[p] = false;
	}
	int c = 0;
	for(int i = 1; i < n; ++i) c += vis[i];
	cout << c << '\n';
	for(int i = 1; i < n; ++i) if(vis[i]) cout << i << ' ';
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
