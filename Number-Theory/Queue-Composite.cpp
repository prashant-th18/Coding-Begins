#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const ll MOD = 998244353;
#define ff first
#define ss second
using pll = pair<ll, ll>;

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
ll mul(ll a, ll b) {
	return a * b % MOD;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return (a - b + MOD) % MOD;
}

// *-> KISS*
int solve() {
    int m; cin >> m;
	queue<pll> q;
	ll prod = 1, ans = 1; // prod stores product of all a's 
						  // ans stores till now, If x = 1, then what is the value of these queries
	while(m--) {
		ll t; cin >> t;
		if(t == 0) {
			ll a, b; cin >> a >> b;
			q.push(pll(a, b));
			prod = mul(prod, a);
			ans = add(mul(a, ans), b);
		}
		else if(t == 1) {
			// Remove First
			pll f = q.front(); q.pop();
			ll removeF = mul(prod, modinv(f.ff));
			
			ll pre = mul(removeF, add(f.ff, f.ss));
			ans = sub(ans, pre);
			
			ll ahead = removeF;
			ans = add(ans, ahead);
			prod = ahead;
		}
		else {
			ll x; cin >> x;
			if(q.empty()) {
				cout << x << '\n';
			}
			else {
				ll dif = x - 1;
				ll temp = mul(prod, dif);
				temp = add(temp, ans);
				cout << temp << '\n';
			}
		}
	}
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
