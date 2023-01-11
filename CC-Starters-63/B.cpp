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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// Use -> unordered_map<key_type, value_type, custom_hash> mp;
// *-> KISS*
int solve() {
    int n; cin >> n;
	string a, b; cin >> a >> b;
	// [0 .. 1][0 .. n - 1][0 .. 51]
	vector<vector<vector<bool>>> dp(2, 
			vector<vector<bool>>(n, vector<bool>(52, false)));
	auto diff = [&](char c1, char c2) {
		int num = 0;
		if(c1 <= c2) num = c2 - c1;
		else {
			num = 'z' - c1;
			num += (c2 - 'a') + 1;
		}
		return num;
	};
	const int extra = 25;
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			int dif1 = diff(a[i], b[i]);
			dp[0][i][dif1 + extra] = true;

			dif1 = -1 * diff(b[i], a[i]);
			dp[1][i][dif1 + extra] = true;
		}
		else {
			int dif1 = diff(a[i], b[i]);
			for(int j = -25; j <= 25; ++j) {
				if(dp[0][i - 1][j + extra] || dp[1][i - 1][j + extra]) {
					int add = j + dif1;
					if(-25 <= add && add <= 25) {
						dp[0][i][add + extra] = true;
					}
				}
			}

			dif1 = -1 * diff(b[i], a[i]);
			for(int j = -25; j <= 25; ++j) {
				if(dp[0][i - 1][j + extra] || dp[1][i - 1][j + extra]) {
					int add = j + dif1;
					if(-25 <= add && add <= 25) {
						dp[1][i][add + extra] = true;
					}
				}
			}
		}
	}
	int minn = 26;
	for(int i = -25; i <= 25; ++i) {
		if(dp[0][n - 1][i + extra] || dp[1][n - 1][i + extra]) minn = min(minn, abs(i));
	}
	cout << minn;
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
