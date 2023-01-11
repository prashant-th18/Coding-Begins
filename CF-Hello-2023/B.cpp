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

vector<int> v;
bool ans = false;
void fun(int in) {
	if(in == sz(v)) {
		bool f = true;
		int s = accumulate(all(v), 0);
		for(int i = 0; i < sz(v) - 1; ++i) {
			if(s == v[i] + v[i + 1]) {}
			else {
				f = false;
				break;
			}
		}
		if(f) {
			for(auto val : v) cout << val << ' ';
			cout << endl;
		}
		ans = ans | f;
		return;
	}
	
	for(int i = -3; i <= 3; ++i) {
		if(i == 0) continue;
		v[in] = i;
		fun(in + 1);
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    // v.assign(n, 0);
    // fun(0);
    if(n % 2 == 0) {
    	cout << "YES\n";
    	for(int i = 0; i < n; ++i) {
    		if(i & 1) cout << -1;
    		else cout << 1;
    		cout << ' ';
    	}
    }
    else {
    	if(n == 3) cout << "NO";
    	else {
    		cout << "YES\n";
    		int num = (n + 1) >> 1;
    		num -= 2;
    		for(int i = 0; i < n; ++i) {
    			if(i & 1) cout << -(num + 1);
    			else cout << num;
    			cout << ' ';
    		}
    	}
    }
	return 0;
}
int32_t main() {
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
