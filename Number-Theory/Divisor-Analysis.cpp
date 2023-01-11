#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const ll MOD = 1000000007;
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
ll modinv(ll x) {
	return binexp(x, MOD - 2);
}

ll number(vector<ll>& prime, vector<ll>& expo) {
	// expo + 1
	ll num = 1;
	for(int i = 0; i < sz(expo); ++i) {
		num = num * (expo[i] + 1) % MOD;
	}
	return num;
}
ll sum(vector<ll>& prime, vector<ll>& expo) {
	ll s = 1;
	for(int i = 0; i < sz(prime); ++i) {
		ll num = (binexp(prime[i], expo[i] + 1) - 1 + MOD) % MOD * modinv(prime[i] - 1) % MOD;
		s = s * num % MOD;
	}
	return s;
}
ll product(vector<ll>& prime, vector<ll>& expo) {
	// Since we know that, product of all divisors of a number is equal to:
	// n ^ ((number of divisors) / 2)

/* Now, we know that, since number of divisors can be quite large, what we can do is that, we can say: */
	/* a ^ b % MOD {where b is quite large} = a ^ (b % (MOD - 1)) % MOD */

	// But, there's a catch, we also have to divide our number of divisors by 2, but if we take that number of divisors % (MOD - 1) then we can't calculate modinv of "2", as for that, we need to have "2" and "MOD - 1" co-prime, which they aren't.
	//
	// So we have (a^b * c^d) ^ f 
	// This can be written as: a ^ (b * f) * c ^ (d * f)
	//
	// So, you will say, 
	// n = prime[0] ^ (expo[0] * (no. of div) / 2) * ....

	ll prod = 1;
	int in = -1;
	for(int i = 0; i < sz(expo); ++i) {
		if(expo[i] & 1) {
			in = i;
		}
	}
	if(in != -1) {
		// That means at-least one of the expo is "odd", therefore, in that product of divisors, 
		// one of them is even, so we can simply divide it by 2.
		ll outerExpo = 1;
		for(int i = 0; i < sz(expo); ++i) {
			if(i == in) {
				outerExpo = outerExpo * ((expo[i] + 1) / 2) % (MOD - 1);
			}
			else {
				outerExpo = outerExpo * (expo[i] + 1) % (MOD - 1);
			}
		}
		for(int i = 0; i < sz(expo); ++i) {
			prod = prod * binexp(prime[i], expo[i] * outerExpo % (MOD - 1)) % MOD;
		}
	}
	else {
		ll outerExpo = 1;
		for(int i = 0; i < sz(expo); ++i) {
			outerExpo = outerExpo * (expo[i] + 1) % (MOD - 1);
		}
		// All expo[i] is even
		for(int i = 0; i < sz(expo); ++i) {
			prod = prod * binexp(prime[i], expo[i] / 2 * outerExpo % (MOD - 1)) % MOD;
		}
	}
	return prod;
}
// *-> KISS*
int solve() {
    ll n; cin >> n;
	vector<ll> prime(n), expo(n);
	for(int i = 0; i < n; ++i) {
		cin >> prime[i] >> expo[i];
		// Okay, is prime no. prime[i] ke corresponding power jo hai, vo hai -> expo[i]
	}
	cout << number(prime, expo) << ' ' << sum(prime, expo) << ' ' << product(prime, expo);
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
