#include <unordered_map>
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
const int N = 2e7 + 1;
vector<ll> pr;
vector<bool> prime;
unordered_map<ll, ll, custom_hash> mp;
void init() {
	prime.assign(N + 1, true);
	prime[1] = false;
	for(int i = 4; i < N; i += 2) prime[i] = false;
	
	mp[4] = 2;
	pr.push_back(2);
	for(ll i = 3; i < N; i += 2) {
		if(prime[i]) {
			pr.push_back(i);
			mp[i * i] = i;
			for(ll j = i * i; j < N; j += 2 * i) {
				prime[j] = false;
			}
		}
	}
}
// *-> KISS*
int solve() {
	ll n; cin >> n;
	for(int i = 0; i < sz(pr); ++i) {
		ll num = pr[i];
		// P
		if(num * num < n && (n % (num * num) == 0)) {
			ll left = (n / num) / num;
			if(left < N && prime[left] && left != num) {
				cout << num << ' ' << left;
				return 0;
			}
		}
		
		// Q
		if(n % num == 0) {
			ll left = n / num;
			if(mp.count(left) && mp[left] != num) {
				cout << mp[left] << ' ' << num;
				return 0;
			}
		}
	}
	assert(false);
	return 0;
}
int32_t main() {
    init();
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