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
int ans = INT_MAX;
void fun(vector<int> v, int in, int val = 0) {
	if(in == -1) ans = min(ans, val);
	else {
		int cnt = 0;
		for(int i = 0; i < sz(v); ++i) {
			cnt += ((v[i] >> in) & 1);
		}
		if(cnt == 0 || cnt == sz(v)) {
			fun(v, in - 1, val);
		}
		else {
			vector<int> z, o;
			for(int i = 0; i < sz(v); ++i) {
				if((v[i] >> in) & 1) o.push_back(v[i]);
				else z.push_back(v[i]);
			}
			if(sz(z) != 0) fun(z, in - 1, val | (1 << in));
			if(sz(o) != 0) fun(o, in - 1, val | (1 << in));	
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	fun(v, 29);
	/* int maxx = 0; */
	/* for(int i = 0; i < n; ++i) { */
	/* 	maxx = max(maxx, v[i] ^ ans); */
	/* } */
	cout << ans;
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
