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
const int N = 5e4 + 1;
vector<ll> pr;
vector<int> vis(N, -1);
void init() {
	pr.push_back(2);
	for(int i = 2; i < N; i += 2) vis[i] = 2;
	for(int i = 3; i < N; i += 2) {
		if(vis[i] == -1) {
			pr.push_back(i);
			for(ll j = (ll)i * i; j < N; j += 2 * i) {
				vis[j] = i;
			}
		}
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v(n);
    int even = 0;
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    	even += (v[i] % 2 == 0);
    }
    unordered_map<int32_t, int32_t, custom_hash> cnt, mp;
    for(int i = 0; i < n; ++i) {
    	cnt[v[i]]++;
    	if(v[i] != 1 && cnt[v[i]] > 1) {
    		cout << "YES"; return 0;
    	}
    }
    
    for(int i = 0; i < n; ++i) {
    	for(auto& val : pr) {
    		if(val * val > v[i]) {
    			break;
    		}
    		int c = 0;
    		while(v[i] % val == 0) {
    			c++;
    			v[i] /= val;
    		}
    		if(c) mp[val]++;
    	}
    	if(v[i] != 1) mp[v[i]]++;
    }
    for(auto val : mp) {
    	if(val.ss > 1) {
    		cout << "YES"; return 0;
    	}
    }
    cout << "NO";
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
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
