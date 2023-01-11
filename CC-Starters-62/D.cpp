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

template<typename T>
T binexp(T a, T b) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1LL * ans * a % MOD;
		}
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return ans;
}
ll answer(string& a, string& b) {
	ll ans = 0;
	for(int i = sz(a) - 1; i >= 0; --i) {
		char c1 = a[i] - '0', c2 = b[i] - '0';
		if(c1 != c2) {
			ans = (ans + binexp(2, sz(a) - 1 - i)) % MOD;
		}
	}
	return ans;
}
// *-> KISS*
int solve() {
	int n; cin >> n;
    string s; cin >> s;
	if(int a = count(all(s), '0'); a == n || a == 0) {
		cout << 0; return 0;
	}
	auto fun = [&](char ch) {
		int in = s.find(ch);
		string one = s.substr(in);
		int how = 0;
		for(int i = in; i < sz(s); ++i) {
			if(s[i] == ch) ++how;
			else break;
		}
		in = max(0, in - how);
		string two = s.substr(in, sz(one));
		cout << answer(one, two);
	};
	if(s[0] == '1') fun('0');
	else fun('1');
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
