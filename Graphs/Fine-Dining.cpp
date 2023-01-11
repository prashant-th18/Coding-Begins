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

using pll = pair<ll, ll>;
struct node {
	ll dis, elem;
	
	bool operator<(const node& other) const {
		if(dis != other.dis) return dis < other.dis;
		
		return elem < other.elem;
	}
};
// *-> KISS*
int solve() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<pll>> v(n + 1);
    for(int i = 0; i < m; ++i) {
    	ll a, b, c; cin >> a >> b >> c;
    	v[a].push_back({b, c});
    	v[b].push_back({a, c});
    }
    vector<bool> vis(n + 1, false);
    unordered_map<int, ll, custom_hash> mp;
    for(int i = 0; i < k; ++i) {
    	ll a, y; cin >> a >> y;
    	vis[a] = true;
    	if(mp.find(a) == mp.end()) mp[a] = y;
    	else mp[a] = max(mp[a], y);
    }
    
    vector<ll> dist(n + 1, 1e18);
    dist[n] = 0;
    set<node> st;
    st.insert({0, n});
    while(!st.empty()) {
    	node p = *(st.begin()); st.erase(st.begin());
    	
    	ll dis = p.dis, elem = p.elem;
    	
    	if(dist[elem] < dis) continue;
    	
    	for(const auto& val : v[elem]) {
    		if(val.ss + dis < dist[val.ff]) {
    			dist[val.ff] = dis + val.ss;
    			vis[val.ff] = vis[val.ff] | vis[elem];
    			st.insert({val.ss + dis, val.ff});
    		}
    		else if(val.ss + dis == dist[val.ff]) {
    			vis[val.ff] = vis[val.ff] | vis[elem];
    		}
    	}
    }
    
    bool allTrue = false;
	for(auto val : mp) {
		if(val.ss >= dist[val.ff] * 2) {
			allTrue = true;
		}
	}
	for(int i = 1; i <= n - 1; ++i) {
		vis[i] = vis[i] | allTrue;
		if(vis[i]) cout << 1;
		else cout << 0;
		cout << '\n';
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
        // cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!