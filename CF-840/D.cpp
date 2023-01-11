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
ll fact[101] {1};
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
ll modinv(ll b) {
	return binexp(b, (ll)MOD - 2);
}
ll ncr(ll n, ll r) {
	if(r > n || r < 0) return 0;
	
	return fact[n] * modinv(fact[r]) % MOD * modinv(fact[n - r]) % MOD;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll mul(ll a, ll b) {
	return a * b % MOD;
}

// *-> KISS*
int solve() {
    ll n, i, j, x, y; cin >> n >> i >> j >> x >> y;
    
    ll ans = 0;
    
    if(x < y) {
    	for(int k = i + 1; k < n; ++k) {
    		// Assuming peak at k
    		
    		if(k == j) {
    			if(y != n) continue;
    			
    			int bt = j - i - 1;
    			int left = i;
    			
    			int elem1 = y - x - 1; // x + 1 ... y - 1;
    			
    			ans = add(ans, mul(ncr(elem1, bt), ncr(left, x - 1))); 
    		}
    		else if(k < j) {
    			if(y == n) continue;
    			
    			
    		}
    	}
    }
    else {
    	
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i < 101; ++i) {
    	if(i == 0) fact[i] = 1;
    	else fact[i] = i * fact[i - 1] % MOD;
    }
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