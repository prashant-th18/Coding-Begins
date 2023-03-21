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

vector<int> order;
int mat[6][6];
void rec(int n, int select, int i) {
	if(select == 0) {
		int c = 1;
		for(auto val : order) {
			mat[val][c++]++;
		}
		return;
	}
	if(i > n) return;
	// Either select or not select
	
}
// *-> KISS*
int solve() {
	for(int i = 0; i <= 5; ++i) {
		for(int j = 0; j <= 5; ++j) {
			mat[i][j] = 0;
		}
	}
	for(int i = 1; i <= 5; ++i) {
		rec(5, i, 0);
	}
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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
