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
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	int maxx = 40;
	for(int i = 1; i < n - 1; ++i) {
		if(v[i] == v[i + 1]) {
			maxx = 1; break;
		}
	}
	for(int i = n - 2; i >= 0; --i) {
		int XOR = v[i + 1];
		for(int j = i + 2; j < min(n, i + 32); ++j) {
			XOR ^= v[j];
			if(v[i] > XOR) {
				maxx = min(maxx, j - i - 1);
				break;
			}
		}
		XOR = v[i];
		for(int j = i + 1; j < min(n, i + 32); ++j) {
			XOR ^= v[j];
			int ahead = 0;
			for(int k = j + 1; k < min(n, i + 32); ++k) {
				ahead ^= v[k];
				if(XOR > ahead) {
					maxx = min(maxx, j - i + (k - (j + 1)));
				}
			}
		}
	}
	if(maxx == 40) maxx = -1;
	cout << maxx;
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
