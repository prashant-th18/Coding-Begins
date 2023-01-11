#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6;
vector<ll> two, fact;
ll binexp(ll base, ll power) {
	ll res = 1;
	while(power) {
		if(power & 1) {
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		power >>= 1;
	}
	return res;
}
ll modinv(ll num) {
	return binexp(num, MOD - 2);
}
ll ncr(ll n, ll r) {
	if(r < 0 || r > n) return 0;
	
	return fact[n] * modinv(fact[n - r]) % MOD * modinv(fact[r]) % MOD;
}
void init() {
	two.assign(N, 0);
	two[0] = 1;
	for(ll i = 1; i < N; ++i) {
		two[i] = (2LL * two[i - 1]) % MOD;
	}
	
	fact.assign(N, 1);
	for(ll i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}	
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return (a - b + MOD) % MOD;
}
ll mul(ll a, ll b) {
	return (a % MOD) * (b % MOD) % MOD;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> must(2, 0);
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
    	ll len = 2 * (i + 1) - 1;
    	int num = (s[i] - '0');
    	if(num == 1) {
    		must[1]++;
    		if(must[1] > i) {
    			// Ok
    			ll left = len - must[1] - must[0];
    			ans = add(ans, two[left]);
    		}
    		else {
    			ll left = len - must[0] - must[1];
    			ll dif = (i + 1) - must[1];
    			
    			if(dif > left) break;
    			
    			must[1] += dif;
    			left = len - must[1] - must[0];
    			ans = add(ans, two[left]);
    		}
    	}
    	else {
    		++must[0];
    		if(must[0] > i) {
    			ll left = len - must[1] - must[0];
    			ans = add(ans, two[left]);
    		}
    		else {
    			ll left = len - must[0] - must[1];
    			ll dif = (i + 1) - must[0];
    			
    			if(dif > left) break;
    			
    			must[0] += dif;
    			left = len - must[1] - must[0];
    			ans = add(ans, two[left]);
    		}
    	}
    }
    cout << ans;
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
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
