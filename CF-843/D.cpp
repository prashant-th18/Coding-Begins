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
const int N = 3e5 + 1;
vector<int> spf;
void init() {
	spf.assign(N + 1, -1);
	for(int i = 2; i <= N; i += 2) spf[i] = 2;
	
	for(ll i = 3; i <= N; i += 2) {
		if(spf[i] == -1) {
			for(ll j = i; j < N; j += 2 * i) spf[j] = i;
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    unordered_map<int, set<int>, custom_hash> mp;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	int t = v[i];
    	vector<int> order;
    	while(spf[t] != -1) {
    		int ok = spf[t];
    		order.push_back(ok);
    		while(t % ok == 0) t /= ok;
    	}
    	for(const auto& val : order) {
    		mp[val].insert(i);
    	}
    }
    
    int s, t; cin >> s >> t;
    vector<int> par(n + 1, -1);
    vector<bool> vis(N + 1, false);
    vector<bool> vi(n + 1, false);
    // BFS
    using pii = pair<int, int>;
    queue<pii> q;
    q.push({s, 0});
    while(!q.empty()) {
    	pii p = q.front(); q.pop();
    	int t = v[p.ff];
    	vector<int> order;
    	while(spf[t] != -1) {
    		int ok = spf[t];
    		order.push_back(ok);
    		while(t % ok == 0) t /= ok;
    	}
    	for(const auto& val : order) {
    		if(!vis[val]) {
    			vis[val] = true;
    			set<int>& st = mp[val];
                vi[p.ss] = true;
                st.erase(p.ss);
                for(auto& vall : st) {
                    if(!vi[p.ss]) {
                        vi[p.ss] = true;
                        q.push({})
                    }
                }
    		}
    	}
    }
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