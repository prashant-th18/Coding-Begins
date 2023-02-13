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
	n *= 2;
	// vector<int> v(n);
	// iota(all(v), 1);
	// do {
	// 	vector<ll> s;
	// 	for(int i = 0; i < n; ++i) {
	// 		s.push_back(v[i] + v[i + 1]);
	// 		++i;
	// 	}
	// 	bool f = true;
	// 	for(int i = 1; i < sz(s); ++i) {
	// 		if(s[i] - s[i - 1] == 1) {}
	// 		else f = false;
	// 	}
	// 	if(f) {
	// 		for(auto val : v) cout << val << ' ';
	// 		cout << endl;
	// 	}
	// } while(next_permutation(all(v)));
	if(n % 4 == 0) {
		cout << "NO\n"; return 0;
	}
	cout << "YES\n";
	int f1 = 1, f2 = n - (n / 4);
	while(f1 < f2) {
		cout << f1 << ' ' << f2 << '\n';
		f1 += 2;
		f2--;
	}
	f1 = 2; f2 = n;
	while(f2 > (n - (n / 4))) {
		cout << f1 << ' ' << f2 << '\n';
		f1 += 2;
		f2--;
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
