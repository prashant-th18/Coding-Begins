#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
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
typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> x(n + 1);
    for(int i = 0; i < n; ++i) cin >> x[i + 1];
    
    vector<vector<int>> ladders(n + 1);
	unordered_map<int, unordered_map<int, vector<vector<ll>>, custom_hash>, custom_hash> mp;
	
	vector<vector<int>> row(n + 1);
	
	for(int i = 0; i < k; ++i) {
		ll a, b, c, d, h; cin >> a >> b >> c >> d >> h;
		mp[a][b].push_back({c, d, h});
		row[a].push_back(b);
	}
	
	for(int i = 0; i < n; ++i) sort(all(row[i + 1]));
	
	// map<pair<int, int>, ll> dist;
	unordered_map<int, unordered_map<int, ll, custom_hash>, custom_hash> dist;
	// dist
	dist[1][1] = 0;
	ladders[n].push_back(m);
	ladders[1].push_back(1);
	dist[n][m] = LLONG_MAX;
	for(int i = 1; i <= n; ++i) {
		
		for(int j = 0; j < sz(row[i]); ++j) {
			ladders[i].push_back(row[i][j]);
			pair<int, int> f = pair{i, row[i][j]};
			if(dist[i].find(row[i][j]) == dist[i].end()) dist[f.ff][f.ss] = LLONG_MAX;
		}
		
		sort(all(ladders[i]));
		
		vector<int>& here = ladders[i];
		for(int j = 0; j < sz(here) - 1; ++j) {
			// j, j + 1
			pair<int, int> f = {i, here[j]};
			pair<int, int> s = {i, here[j + 1]};
			ll diff = here[j + 1] - here[j];
			if(dist[f.ff][f.ss] != LLONG_MAX) dist[s.ff][s.ss] = min(dist[s.ff][s.ss], dist[f.ff][f.ss] + diff * x[i]);
		}
		
		for(int j = sz(here) - 1; j >= 1; --j) {
			// j, j - 1
			pair<int, int> f = {i, here[j]};
			pair<int, int> s = {i, here[j - 1]};
			ll diff = here[j] - here[j - 1];
			if(dist[f.ff][f.ss] != LLONG_MAX) dist[s.ff][s.ss] = min(dist[s.ff][s.ss], dist[f.ff][f.ss] + diff * x[i]);
		}
		
		for(int j = 0; j < sz(row[i]); ++j) {
			pair<int, int> p = pair{i, row[i][j]};
			ll dis = dist[p.ff][p.ss];
			if(dis == LLONG_MAX) continue;
			for(auto& val : mp[p.ff][p.ss]) {
				int ni = val[0], nj = val[1], d = val[2];
				if(dist[ni].find(nj) == dist[ni].end()) {
					dist[ni][nj] = dis - d;
					ladders[ni].push_back(nj);
				}
				else {
					dist[ni][nj] = min(dist[ni][nj], dis - d);
				}
			}
		}
	}
	if(dist[n][m] == LLONG_MAX) cout << "NO ESCAPE";
	else cout << dist[n][m];
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