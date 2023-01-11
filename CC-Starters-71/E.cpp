// #include <climits>
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

int minn = 0, maxx = 0;
int n, m;
void get(vector<vector<int>>& ok, int i, int j) {
	minn = min(minn, ok[i][j]);
	maxx = max(maxx, ok[i][j]);
	if(i == n - 1 && j == m - 1) return;
	int d = (i + j) % 2;
	if(d % 2 == 0) {
		int m1 = (j + 1 < m) ? (ok[i][j + 1]) : (INT_MIN);
		int m2 = (i + 1 < n) ? (ok[i + 1][j]) : (INT_MIN);
		if(m1 > m2) get(ok, i, j + 1);
		else get(ok, i + 1, j);
	}
	else {
		int m1 = (j + 1 < m) ? (ok[i][j + 1]) : (INT_MAX);
		int m2 = (i + 1 < n) ? (ok[i + 1][j]) : (INT_MAX);
		if(m1 < m2) get(ok, i, j + 1);
		else get(ok, i + 1, j);
	}
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    vector<int> v(n * m);
    for(int i = 0; i < n * m; ++i) cin >> v[i];
    sort(all(v));
	int dif = n + 2 * m - 2;
	int i = 0, j = dif;
	int ans = v[j - 1] - v[1];
	int bi = 0, bj = j - 1;
	while(j < n * m) {
		++i;
		if(v[j] - v[i + 1] < ans) {
			ans = v[j] - v[i + 1];
			bi = i, bj = j;
		}
		++j;
	}
	
	vector<int> temp;
	for(int i = bi; i <= bj; ++i) {
		temp.push_back(v[i]);
	}
	vector<int> ex;
	for(int i = 0; i < bi; ++i) {
		ex.push_back(v[i]);
	}
	for(int i = bj + 1; i < n * m; ++i) {
		ex.push_back(v[i]);
	}
	
	vector<vector<int>> ok(n, vector<int>(m, 0));
	
	int in = 0;
	ok[0][0] = temp[1];
	ok[1][0] = temp[0];
	ok[0][1] = temp[2];
	in = 3;
	for(int j = 1; j < m - 1; ++j) {
		if(j % 2 == 0) {
			ok[1][j] = temp[in++];
			ok[0][j + 1] = temp[in++];
		}
		else {
			ok[0][j + 1] = temp[in++];
			ok[1][j] = temp[in++];
		}
	}
	{
		for(int i = 1; i < n; ++i) ok[i][m - 1] = temp[in++];
	}
	assert(in == sz(temp));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(ok[i][j] == 0) {
				ok[i][j] = ex.back();
				ex.pop_back();
			}
			cout << ok[i][j] << ' ';
		}
		cout << '\n';
	}
	minn = 1e9 + 1, maxx = 0;
	get(ok, 0, 0);
	// cout << maxx << ' ' << minn << endl;
	assert(maxx - minn == ans);
	assert(sz(ex) == 0);
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
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!