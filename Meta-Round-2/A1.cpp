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
	string s; cin >> s;
	int n = sz(s);
	vector<vector<int>> v(n + 1, vector<int>(26, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 26; ++j) {
			v[i + 1][j] = v[i][j] + (s[i] - 'a' == j);
		}
	}
	int q, c = 0; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		if((r - l) & 1) continue;
		
		int mid = (l + r) >> 1;
		// [l .. mid]
		vector<int> left(26, 0), right(26, 0);
		for(int j = 0; j < 26; ++j) {
			left[j] = v[mid][j] - v[l - 1][j];
			right[j] = v[r][j] - v[mid][j];
		}
		// Either remove from left or from right
		// From left
		int how = 0;
		for(int j = 0; j < 26; ++j) {
			if(left[j] == right[j]) continue;
			else {
				if(right[j] > left[j]) how = 2;
				else {
					if(left[j] - 1 == right[j]) ++how;
					else {
						how = 2;
					}
				}
			}
		}
		if(how == 1) {
			++c; continue;
		}
		// From right
		for(int j = 0; j < 26; ++j) {
			left[j] -= (v[mid][j] - v[mid - 1][j]);
			right[j] += (v[mid][j] - v[mid - 1][j]);
		}
		how = 0;
		for(int j = 0; j < 26; ++j) {
			if(left[j] == right[j]) continue;
			else {
				if(left[j] > right[j]) how = 2;
				else {
					if(left[j] == right[j] - 1) ++how;
					else how = 2;
				}
			}
		}
		if(how == 1) {
			++c;
		}
	}
	cout << c;
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
		cout << "Case #" << i << ": ";
		#ifdef LOCAL
        	cerr << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
