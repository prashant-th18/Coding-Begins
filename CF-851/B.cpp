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

// *-> KISS*
int solve() {
    ll n; cin >> n;
    ll a = 0, b = 0;
    ll res = 1;
    bool flag = false;
    while(n) {
    	int num = n % 10;
    	n /= 10;
    	int x = num / 2, y = (num + 1) / 2;
    	if(x == y) {
    		a += x * res;
    		b += y * res;
    	}
    	else {
    		if(flag) {
    			a += y * res;
    			b += x * res;
    			flag = false;
    		}
    		else {
    			a += x * res;
    			b += y * res;
    			flag = true;
    		}
    	}
    	res *= 10;
    }
    cout << a << ' ' << b;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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