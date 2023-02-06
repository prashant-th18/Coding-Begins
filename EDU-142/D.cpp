#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000009;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int getHash(vector<int>& t, int len) {
	int p = 1;
	int ans = 0;
	for(int i = 0; i < len; ++i) {
		int num = (1LL * t[i] * p % MOD);
		ans = (ans + num) % MOD;
		p = p * 31LL % MOD;
	}
	return ans;
}
vector<int> getArray(vector<int>& t, int len) {
	vector<int> temp;
	for(int i = 0; i < len; ++i) {
		temp.push_back(t[i]);
	}
	return temp;
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < m; ++j) cin >> v[i][j];
    }
	vector<vector<int>> t(n);
	vector<set<int>> st(m + 1);
	vector<set<vector<int>>> pres(m + 1);
	for(int i = 0; i < n; ++i) {
		vector<int> pos(11, 0);
		for(int j = 0; j < m; ++j) pos[v[i][j]] = j + 1;
		
		for(int j = 1; j <= 10; ++j) {
			t[i].push_back(pos[j]);
		}
		vector<int> temp;
		int p = 1;
		int ans = 0;
		for(int len = 1; len <= m; ++len) {
			int num = (1LL * t[i][len - 1] * p % MOD);
			ans = (ans + num) % MOD;
			p = p * 31LL % MOD;
			st[len].insert(ans);
			temp.push_back(t[i][len - 1]);
			pres[len].insert(temp);
		}
	}
	for(int i = 0; i < n; ++i) {
		int here = 0;
		int p = 1;
		int ans = 0;
		vector<int> temp;
		for(int j = 0; j < m; ++j) {
			int num = (1LL * v[i][j] * p % MOD);
			ans = (ans + num) % MOD;
			p = p * 31LL % MOD;
			temp.push_back(v[i][j]);
			if(st[j + 1].count(ans) && pres[j + 1].count(temp)) {
				here = j + 1;
			}
		}
		cout << here << ' ';
	}
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