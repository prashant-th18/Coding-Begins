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

int n, m;
vector<string> v;
int P() {
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cnt += (v[i][j] == 'P');
		}
	}
	return cnt;
}
bool border() {
	bool ans = false;
	bool f1 = true, f2 = true;
	for(int j = 0; j < m; ++j) (f1 &= (v[0][j] == 'A')), (f2 &= (v[n - 1][j] == 'A'));
	ans |= f1;
	ans |= f2;
	f1 = true; f2 = true;
	for(int i = 0; i < n; ++i) (f1 &= (v[i][0] == 'A')), (f2 &= (v[i][m - 1] == 'A'));
	ans |= f1; ans |= f2;
	return ans;
}
bool edge() {
	return (v[0][0] == 'A') || (v[0][m - 1] == 'A') || (v[n - 1][0] == 'A') || (v[n - 1][m - 1] == 'A');
}
bool HV() {
	for(int i = 1; i < n - 1; ++i) {
		bool f = true;
		for(int j = 0; j < m; ++j) f &= (v[i][j] == 'A');
		if(f) return true;
	}
	for(int j = 1; j < m - 1; ++j) {
		bool f = true;
		for(int i = 0; i < n; ++i) f &= (v[i][j] == 'A');
		if(f) return true;
	}
	return false;
}
bool betweenEdge() {
	bool f1 = false;
	for(int j = 1; j < m - 1; ++j) (f1 |= (v[0][j] == 'A')), (f1 |= (v[n - 1][j] == 'A'));
	for(int i = 1; i < n - 1; ++i) (f1 |= (v[i][0] == 'A')), (f1 |= (v[i][m - 1] == 'A'));
	return f1;
}
// *-> KISS*
int solve() {
    cin >> n >> m;
	v.assign(n, "");
	for(int i = 0; i < n; ++i) cin >> v[i];
	if(P() == 0) {
		cout << 0;
		return 0;
	}
	if(P() == n * m) {
		cout << "MORTAL"; return 0;
	}
	if(border()) {
		cout << 1;
	}
	else if(edge() || HV()) {
		cout << 2;
	}
	else if(betweenEdge()) {
		cout << 3;
	}
	else cout << 4;
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
