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
using pll = pair<ll, ll>;
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
	vector<vector<pll>> v(n + 1);
	vector<array<ll, 3>> every;
	for(int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
		every.push_back({a, b, c});
	}
	sort(all(every), [&](array<ll, 3> t1, array<ll, 3> t2) {
			return t1[2] > t2[2];
	});
	ll ans = 0;
	vector<set<pll>> dp(n + 1);
	for(int i = 0; i < sz(every); ++i) {
		int a = every[i][0], b = every[i][1], c = every[i][2];
		set<pll>& ahead = dp[b];
		set<pll>& me = dp[a];
		auto it = ahead.lower_bound(pll(c + 1, 0));
		ll w, adv;
		if(it == ahead.end()) {
			w = c, adv = 1;
		}
		else {
			w = c, adv = 1 + (it -> second);
		}
		ans = max(ans, adv);
		me.insert(pll(w, adv));
		it = me.upper_bound(pll(w, adv));
		if(it != me.end() && (it -> second >= adv)) {
			--it;
			me.erase(it);
			continue;
		}
		else {
			it = me.find(pll(w, adv));
			while(it != me.begin()) {
				--it;
				if(adv >= (it -> second)) {
					it = me.erase(it);
				}
				else break;
			}
		}
	}
	cout << ans;
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
