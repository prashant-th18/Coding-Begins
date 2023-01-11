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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

using pll = pair<ll, ll>;
// *-> KISS*
int solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> x(n + 1);
    for(int i = 0; i < n; ++i) cin >> x[i + 1];
    	
    map<pll, vector<vector<ll>>> mp;
	vector<vector<int>> ladder(n + 1);
    for(int i = 0; i < k; ++i) {
    	ll a, b, c, d, h; cin >> a >> b >> c >> d >> h;
    	mp[pair(a, b)].push_back({c, d, h});
    	ladder[a].push_back(b);
    }
    
    ladder[n].push_back(m);
    
    for(int i = 1; i <= n; ++i) sort(all(ladder[i]));
    
    set<pair<ll, pll>> st;
    map<pll, ll> dist;
    st.insert({0, {1, 1}});
    dist[pair(1, 1)] = 0;
    
    vector<unordered_map<int, int, custom_hash>> up(n + 1), low(n + 1);
    
    auto getUpper = [&](vector<int>& h, int in, int i) {
    	if(up[i].find(in) != up[i].end()) return up[i][in];
    	
    	return up[i][in] = upper_bound(all(h), in) - begin(h);
    };
    
    auto getLower = [&](vector<int>& h, int in, int i) {
    	if(low[i].find(in) != low[i].end()) return low[i][in];
    	
    	return low[i][in] = (lower_bound(all(h), in) - begin(h)) - 1;
    };
    
    auto handle = [&](pair<ll, pll> p) {
    	auto it = st.find(p);
    	if(it == st.end()) return;
    	st.erase(it);
    };
    
    auto upd = [&](vector<int>& here, int in, ll dis, ll i, ll j) {
    	if(in < 0 || in >= sz(here)) return;
    	
    	int nj = here[in];
		ll ndis = dis + (abs(j - nj) * x[i]);
		if(!dist.count(pair(i, nj))) {
			dist[pair(i, nj)] = ndis;
			st.insert({ndis, {i, nj}});
		}
		else if(dist[pair(i, nj)] > ndis) {
			handle(pair(dist[pair(i, nj)], pair(i, nj)));
			dist[pair(i, nj)] = ndis;
			st.insert({ndis, {i, nj}});
		}
    };
    
    while(!st.empty()) {
    	pair<ll, pll> p = *(st.begin());
    	st.erase(st.begin());
    	
    	// Check for right
    	// Agr koi esa hai jha se sidhi chdi jaa skti hai
    	// Toh usko mai minimize krne ki koshish krunga
    	
    	// Similarly, check for left
    	
    	// Now, check for this cell as well, ki yha se koi ladder hai?
    	
    	ll dis = p.ff, i = p.ss.ff, j = p.ss.ss;
    	vector<int>& here = ladder[i];
    	
    	int in1 = getUpper(here, j, i), in2 = getLower(here, j, i);
    	
    	// cout << dis << ' ' << i << ' ' << j << endl;
    	// cout << in1 << ' ' << in2 << endl << endl;
    	
    	upd(here, in1, dis, i, j);
    	upd(here, in2, dis, i, j);
    	
    	for(auto& val : mp[pair(i, j)]) {
    		ll ni = val[0], nj = val[1], h = val[2];
    		
    		ll ndis = dis - h;
    		if(!dist.count(pair(ni, nj))) {
				dist[pair(ni, nj)] = ndis;
				st.insert({ndis, {ni, nj}});
			}
			else if(dist[pair(ni, nj)] > ndis) {
				handle(pair(dist[pair(ni, nj)], pair(ni, nj)));
				dist[pair(ni, nj)] = ndis;
				st.insert({ndis, {ni, nj}});
			}
    	}
    }
    if(!dist.count(pair(n, m))) cout << "NO ESCAPE";
    else cout << dist[pair(n, m)];
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