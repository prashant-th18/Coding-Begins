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

const int N = 1e6 + 10;
vector<vector<vector<int>>> cnt;
void init() {
	cnt.assign(N + 1, vector<vector<int>>(2, vector<int>(2, 0)));
	for(int i = 1; i <= 6; ++i) cnt[i][0][0] = 1;
	for(int i = 2; i <= 6; ++i) {
		cnt[i][1][0] = (i & 1) + cnt[i - 1][1][0];
		cnt[i][1][1] = (i % 2 == 0) + cnt[i - 1][1][1];
	}
	int a = 0, b = 2;
	int curr = 4;
	int how = 0;
	for(int i = 7; i <= N; ++i) {
		if(b == 2) {
			cnt[i][1] = cnt[i - 1][1];
			cnt[i][0][0] = (i & 1) + cnt[i - 1][0][0];
			cnt[i][0][1] = (i % 2 == 0) + cnt[i - 1][0][1];
			++how;
			if(how == curr) {
				++curr;
				how = 0;
				++a;
				if(a == 2) {
					b = 0;
				}
			}
		}
		else {
			cnt[i][0] = cnt[i - 1][0];
			cnt[i][1][0] = (i & 1) + cnt[i - 1][1][0];
			cnt[i][1][1] = (i % 2 == 0) + cnt[i - 1][1][1];
			++how;
			if(how == curr) {
				++curr;
				how = 0;
				++b;
				if(b == 2) a = 0;
			}
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    cout << cnt[n][0][0] << ' ' << cnt[n][0][1] << ' ' << cnt[n][1][0] << ' ' << cnt[n][1][1];
	return 0;
}
int32_t main() {
	init();
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