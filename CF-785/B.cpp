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

// *-> KISS*
int solve() {
    string s; cin >> s;
	int n = sz(s);
	vector<vector<ll>> pre(n + 1, vector<ll>(26, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 26; ++j) {
			pre[i + 1][j] = pre[i][j] + ((s[i] - 'a') == j);
		}
	}
	vector<vector<int>> pos(26);
	for(int i = 0; i < n; ++i) {
		pos[s[i] - 'a'].push_back(i + 1);
	}
	bool flag = true;
	for(int i = 0; i < 26 && flag; ++i) {
		vector<int>& v = pos[i];
		for(int j = 1; j < sz(v) && flag; ++j) {
			int sum = pre[v[j]][i] - pre[v[j - 1] - 1][i];
			for(int k = 0; k < 26 && flag; ++k) {
				if(i == k) continue;
				else {
					int temp = pre[v[j]][k] - pre[v[j - 1] - 1][k];
					if(abs(sum - temp) >= 2 && pre[n][k] > 0) {
						flag = false;
					}
				}
			}
		}
	}
	if(flag) cout << "Yes";
	else cout << "No";
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
