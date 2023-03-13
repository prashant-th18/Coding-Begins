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
	/*
	 * Floyd-Warshall Algo: to calculate distance between each node(not based on L, but rather based on 
	 * number of minimum edges between them)
	 * Then first consider all those pairs of nodes having distance between them == 1
	 * Then those, with distance = 2
	 * Then with distance = 3.
	 * and so on
	 *
	 * While considering each of them, calculate two things: (dp)
	 * - How many times tank needs to be filled
	 * - How many litres of fuel left in the tank
	 *
	 * Suppose we are considering the nodes with distance between them == 2
	 * Here, do transitions:
	 * suppose want to know between a and b
	 * Go through all neighbours of "a", and then take help of dp[neighbour][b] to get the answer for dp[a][b]
	 */

	ll n, m, l; cin >> n >> m >> l;
	vector<array<ll, 3>> v(m);
	for(int i = 0; i < m; ++i) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
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
