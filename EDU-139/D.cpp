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

const int N = 1e7 + 1;
vector<int> spf(N, -1);
void init() {
	for(int i = 2; i < N; ++i) spf[i] = i;
	
	for(int i = 4; i < N; i += 2) spf[i] = 2;
		
	for(int i = 3; i * i < N; i += 2) {
		if(spf[i] == i) {
			for(int j = i * i; j < N; j += 2 * i) {
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
}
// *-> KISS*
int solve() {
    int a, b; cin >> a >> b;
    int diff = b - a;
    if(gcd(a, b) != 1) {
    	cout << 0; return 0;
    }
    if((a % 2) == (b % 2)) {
    	cout << 1; return 0;
    }
    
    vector<int> fact;
    while(spf[diff] != -1) {
    	int num = spf[diff];
    	while(diff % num == 0) {
    		diff /= num;
    	}
    	fact.push_back(num);
    }
    
    int ans = INT_MAX;
    
    for(int i = 0; i < sz(fact); ++i) {
    	int f1 = a % fact[i], f2 = b % fact[i];
    	
    	if(f1 == f2) {
    		int ok = fact[i] - f1;
    		ans = min(ans, ok);
    	}
    }
    if(ans == INT_MAX) ans = -1;
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
