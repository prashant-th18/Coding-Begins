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

vector<ll> p(16);
void init() {
	p[0] = 1;
	for(int i = 1; i < 16; ++i) {
		p[i] = 10LL * p[i - 1];
	}
}
using pll = pair<ll, ll>;

// *-> KISS*
int solve() {
    int n; cin >> n;
	ll ans = 0;
	vector<string> v(n);
	map<char, bool> can; // true means char can't be zero 
	map<char, ll> mp;
	for(int i = 0; i < n; ++i) {
		string& s = v[i];
		for(int j = 0; j < sz(s); ++j) {
			char ch = s[i];
			if('0' <= ch && ch <= '9') {
				int ni = ch - '0';
				ans += (p[sz(s) - j - 1] * ni);
			}
			else {
				if(j == 0) can[ch] = true;
				mp[ch] += (p[sz(s) - j - 1]);
			}
		}
	}
	set<ll> st;
	for(int i = 0; i <= 9; ++i) st.insert(i);
	priority_queue<pll, vector<pll>> pq;
	for(auto& [ch, val] : mp) {
	}
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
	init();
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
