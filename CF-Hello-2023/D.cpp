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
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    	
    for(int i = 0; i < n; ++i) cin >> b[i];
    
    
    int m; cin >> m;
	vector<int> order(m);
	for(int i = 0; i < m; ++i) cin >> order[i];
		
	sort(all(order), greater<int>());
    for(int i = 0; i < n; ++i) {
    	if(a[i] < b[i]) {
    		cout << "NO"; return 0;
    	}
    }
    map<int, deque<int>> mp;
    for(int i = 0; i < n; ++i) {
    	if(a[i] > b[i]) {
    		mp[b[i]].push_back(i);
    	}
    }
    
    const int K = 27;
    vector<vector<int>> rmq(K, vector<int>(n, INT_MIN));
    for(int i = 0; i < n; ++i) {
    	rmq[0][i] = b[i];
    }
    
    for(int i = 1; i < K; ++i) {
    	for(int j = 0; j <= n - (1 << i); ++j) {
    		rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
    	}
    }
    
    auto query = [&](int i, int j) {
		int lg = 31 - __builtin_clz(j - i + 1);
		assert(lg < K);
		return max(rmq[lg][i], rmq[lg][j - (1 << lg) + 1]);
    };
    
    int in = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
    	int num = (it->first);
    	deque<int> dq = (it -> second);
    	while(in < m && order[in] > num) ++in;
    	if(in == m) {
    		cout << "NO"; return 0;
    	}
    	if(order[in] < num) {
    		cout << "NO"; return 0;
    	}
		while(sz(dq)) {
    		int i = dq.front();
    		int last = sz(dq) - 1;
    		for(int j = 0; j < sz(dq); ++j) {
    			int index = dq[j];
    			if(query(i, index) > num) {
    				last = j - 1;
					break;
    			}
    		}
    		int ok = last + 1;
    		while(ok--) dq.pop_front();
    		if(sz(dq) == 0) break;
    		// cout << last << endl;
    		++in;
    		// cout << in << endl;
    		while(in < m && order[in] > num) ++in;
	    	if(in == m) {
	    		cout << "NO"; return 0;
	    	}
	    	if(order[in] < num) {
	    		cout << "NO"; return 0;
	    	}
    	}
    }
    cout << "YES";
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
