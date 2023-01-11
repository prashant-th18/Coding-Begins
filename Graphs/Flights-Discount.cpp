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

using pll = pair<ll, ll>;
struct node {
	ll a, h, w;
	
	bool operator<(const node& other) const {
		if(w != other.w) return w < other.w;
		
		return make_pair(a, h) < make_pair(other.a, other.h);
	}
};
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<vector<pll>> v(n + 1);
    
    for(int i = 0; i < m; ++i) {
    	ll a, b, c; cin >> a >> b >> c;
    	v[a].push_back({b, c});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    set<node> st;
    
    st.insert({1, 1, 0});
    dist[1][1] = 0;
	while(!st.empty()) {
		node f = *(st.begin());
		st.erase(st.begin());
		
		if(dist[f.a][f.h] < f.w) continue;
		
		for(const auto& val : v[f.a]) {
			ll dis = dist[f.a][f.h];
			ll half = f.h;
			ll my = val.ss;
			
			if(dis + my < dist[val.ff][half]) {
				dist[val.ff][half] = dis + my;
				st.insert({val.ff, half, dis + my});
			}
			
			if(half == 1 && 
				(dis + (my / 2) < dist[val.ff][0])) {
				dist[val.ff][0] = dis + my / 2;
				st.insert({val.ff, 0, dis + my / 2});
			}
		}
	}
	cout << min(dist[n][0], dist[n][1]);
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