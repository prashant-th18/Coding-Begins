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
    vector<int> in(n + 1, 0);
    for(int i = 0; i < n - 1; ++i) {
    	int a, b; cin >> a >> b;
    	in[a]++;
    	in[b]++;
    }
    vector<int> v;
    for(int i = 0; i < n; ++i) {
    	if(in[i + 1] == 1) v.push_back(i + 1);
    }
    auto get = [&](int a, int b) {
    	cout << "? " << a << " " << b << endl;
    	int w; cin >> w;
    	return w;
    };
	while(sz(v) >= 2) {
		int a = v.back(); v.pop_back();
		int b = v.back(); v.pop_back();
		int gg = get(a, b);
		if(gg == a || gg == b) {
			cout << "! " << gg << endl;
			return 0;
		}
		v.push_back(gg);
		sort(all(v));
		v.resize(unique(all(v)) - v.begin());
	}
    cout << "! " << v.back() << endl;
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
