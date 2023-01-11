// #include <unordered_map>
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

ll sum = 0;
int n;
vector<ll> value;
vector<vector<ll>> v;
map<pair<ll, ll>, ll> mp;
unordered_map<int, int, custom_hash> col, orig;
vector<ll> ans;
void dfs(int node, int p = -1) {
	vector<int> here;
	for(int val : v[node]) {
		if(val != p) {
			dfs(val, node);
			if(col[value[val]] == 0) {
				sum += value[val];
			}
			
			++col[value[val]];
			here.push_back(value[val]);
			 
			
			ans[mp[make_pair(min(node, val), max(node, val))]] = sum;
		}
	}
	
	sort(all(here));
	here.resize(unique(all(here)) - here.begin());
	// cout << sum << endl;
	for(auto val : here) {
		if(col[val] == orig[val]) {
			sum -= val;
		}
	}
	
	// cout << node << ' ' << sum <<  endl;
}
// *-> KISS*
int solve() {
	sum = 0;
    cin >> n;
    value.assign(n + 1, 0);
    ans.assign(n - 1, 0);
	col.clear(); orig.clear();
	v.assign(n + 1, vector<ll>());
	mp.clear();
    for(int i = 1; i <= n; ++i) cin >> value[i], orig[value[i]]++;
    	
    
	
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		mp[make_pair(min(a, b), max(a, b))] = i;
	}
	dfs(1);
	for(int i = 0; i < sz(ans); ++i) cout << ans[i] << ' ';
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
