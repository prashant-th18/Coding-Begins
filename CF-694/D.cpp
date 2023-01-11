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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 1;
vector<int> spf(N, -1);
void init() {
	for(int i = 2; i < N; ++i) {
		if(spf[i] == -1) {
			for(int j = i; j < N; j += i) {
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	unordered_map<int, int, custom_hash> mp;
	for(int i = 0; i < n; ++i) {
		int x = 1;
		while(v[i] != 1) {
			int num = spf[v[i]];
			if(num == -1) break;
			int c = 0;
			while(v[i] % num == 0) v[i] /= num, ++c;
			if(c & 1) x *= num;
		}
		mp[x]++;
	}
	int max0 = 0;
	for(const auto& val : mp) max0 = max(max0, val.ss);
	unordered_map<int, int, custom_hash> m;
	for(const auto& val : mp) {
		if((val.ff != 1) && (val.ss & 1)) {
			m[val.ff] = val.ss;
		}
		else {
			m[1] += val.ss;
		}
	}
	int max1 = 0;
	for(const auto& val : m) max1 = max(max1, val.ss);
	int q; cin >> q;
	while(q--) {
		ll w; cin >> w;
		if(w == 0) cout << max0 << '\n';
		else cout << max1 << '\n';
	}
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	init();
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
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
