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
    int n, k, maxx = 0; cin >> n >> k;
	vector<int> v(n);
	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		++mp[v[i]];
		maxx = max(maxx, mp[v[i]]);
	}
	if(maxx > 2) {
		cout << "NO"; return 0;
	}
	int p1 = 0, p2 = 0;
	for(auto& val : mp) {
		if(val.ss == 2) {
			++p1, ++p2;
		}
		else {
			if(p1 < p2) ++p1;
			else ++p2;
		}
	}
	if(p1 <= k && p2 <= k) cout << "YES";
	else cout << "NO";
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    bool test = true;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		cout << "Case #" << i << ": ";
        if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!
