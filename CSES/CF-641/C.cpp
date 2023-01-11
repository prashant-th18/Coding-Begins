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
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
vector<int> sieve(N, -1);
void SIEVE() {
	for(int i = 2; i < N; ++i) {
		if(sieve[i] == -1) {
			for(int j = i; j < N; j += i) {
				if(sieve[j] == -1) sieve[j] = i;
			}
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<vector<int>> v(N);
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		while(sieve[t] != -1) {
			int c = 0;
			int num = sieve[t];
			while(t % num == 0) t /= num, ++c;
			v[num].push_back(c);
		}
	}
	for(int i = 2; i < N; ++i) sort(v[i].begin(), v[i].end());
	ll num = 1;
	for(int i = 2; i < N; ++i) {
		if(sz(v[i]) < n - 1) {
			continue;
		}
		else if(sz(v[i]) == n - 1) {
			int t = v[i][0];
			while(t--) num *= i;
		}
		else {
			int t = v[i][1];
			while(t--) num *= i;
		}
	}
	cout << num;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	SIEVE();
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
