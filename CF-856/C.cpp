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
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int res = 1;
	set<pair<int, double>> st;
	st.insert({0, 1.0});
	auto difference = [&](double a, double b) {
		if(abs(a - b) < 1e-9) return false;
		return true;
	};
	for(int i = 0; i < n; ++i) {
		int elem = v[i];
		auto it = st.lower_bound({elem, -1});
		--it;
		int here = (*it).ff + 1;
		res = max(res, here);
		double ok = (*it).ss * elem;
		if(elem != 1 && (here == 1 || difference(ok / here, elem))) {
			auto op = st.lower_bound({here, -1});
			if(op != st.end() && (*op).ff == here && (*op).ss < ok / here) {
				st.erase(op);
				st.insert({here, ok / here});
			}
			else if(op == st.end() || (op != st.end() && (*op).ff != here)) {
				st.insert({here, ok / here});
			}
		}
		cout << res << ' ';
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
