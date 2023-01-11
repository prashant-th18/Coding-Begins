#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const ll MOD = 1000000009;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5;
vector<ll> build(string s) {
	int n = sz(s);
	vector<ll> hash(n + 1, 0);
	ll p = 31;
	for(int i = 1; i <= sz(s); ++i) {
		hash[i] = ((hash[i - 1] * p % MOD) + (s[i - 1] - 'a' + 1)) % MOD;
	}
	return hash;
}
bool check(string a, string b) {
	if(a == b) return true;
	if(sz(a) & 1) return false;
	
	
	vector<int> pre(26);
	for(int i = 0; i < sz(a); ++i) {
		pre[a[i] - 'a']++;
		pre[b[i] - 'a']--;
	}
	
	for(int i = 0; i < 26; ++i) {
		if(pre[i] != 0) {
			return false;
		}
	}
	
	int n = sz(a) / 2;
	bool f1 = check(a.substr(0, n), b.substr(0, n)) && check(a.substr(n), b.substr(n));
	if(f1) return true;
	
	bool f2 = check(a.substr(0, n), b.substr(n)) && check(a.substr(n), b.substr(0, n));
	return f2;
}
// *-> KISS*
int solve() {
    string a, b; cin >> a >> b;
    // re
    // auto h1 = build(a), h2 = build(b);
    
    // // for(int i = 0; i <= sz(a); ++i) cout << h1[i] << ' ';
    // // cout << endl;
	// // for(int i = 0; i < sz(b); ++i) cout << h2[i] << ' ';
	// // cout << endl;
    
    // vector<ll> p(N, 1);
    // for(ll i = 1; i < N; ++i) {
    // 	p[i] = 31LL * p[i - 1] % MOD;
    // }
    
    // auto query = [&](int l, int r, vector<ll>& hash) {
    // 	// Assuming we have l and r as 1 based
    // 	ll num = hash[l - 1] * p[r - l + 1] % MOD;
    // 	num = ((hash[r] - num) % MOD + MOD) % MOD;
    // 	return num;
    // };
    
    // // map<array<int, 3>, bool> mp;
    
    // auto fun = [&](auto&& self, int i, int j, int si) -> bool {
    // 	if(si & 1) {
    // 		return ((query(i + 1, i + si, h1) == query(j + 1, j + si, h2)));
    // 	}
    // 	bool ok = ((query(i + 1, i + si, h1) == query(j + 1, j + si, h2)));
    	
    // 	int i1 = i, i2 = i + si / 2;
    // 	int j1 = j, j2 = j + si / 2;
    // 	if(ok) return ok;
    // 	ok |= (self(self, i1, j1, si / 2) && self(self, i2, j2, si / 2));
    // 	if(ok) return ok;
    // 	ok |= (self(self, i1, j2, si / 2) && self(self, i2, j1, si / 2));
    // 	return ok;
    // };
    cout << (check(a, b) ? ("YES") : ("NO"));
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