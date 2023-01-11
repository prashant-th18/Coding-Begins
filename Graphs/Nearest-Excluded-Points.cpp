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

const int N = 3e5;
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<vector<int>> pre(N);
    map<pair<int, int>, int> ind;
    for(int i = 0; i < n; ++i) {
    	int x, y; cin >> x >> y;
    	pre[x].push_back(y);
    	ind[pair(x, y)] = i;
    }
    for(int i = 1; i < N; ++i) {
    	sort(all(pre[i]));
    }
    
    map<pair<int, int>, array<int, 3>> ans; // Distance, (x, y)
    // Up to Down :
    // 1. Left to Right
    // 2. Right to Left
    
    // Down to Up:
    // 1. Left to Right
    // 2. Right to Left
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    auto handle = [&](pair<int, int> t1, pair<int, int> t2) {
    	array<int, 3> ok;
    	
    	if(!ans.count(t2)) {
    		ok[0] = 1;
    		ok[1] = t2.ff;
    		ok[2] = t2.ss;
    	}
    	else {
    		ok = ans[t2];
    		ok[0]++;
    	}
    	
    	if(!ans.count(t1)) ans[t1] = ok;
    	else if(ans[t1][0] > ok[0]) {
    		ans[t1] = ok;
    	}
    };
    
    for(int i = 1; i < N; ++i) {
    	vector<int>& t = pre[i];
    	for(int j = 0; j < sz(t); ++j) {
    		pair<int, int> p = pair(i, t[j]);
    		handle(p, pair(i, t[j] - 1));
    		handle(p, pair(i - 1, t[j]));
    	}
    	
    	for(int j = sz(t) - 1; j >= 0; --j) {
    		pair<int, int> p = pair(i, t[j]);
    		handle(p, pair(i, t[j] + 1));
    	}
    }
    
    for(int i = N - 1; i >= 0; --i) {
    	vector<int>& t = pre[i];
    	for(int j = 0; j < sz(t); ++j) {
    		pair<int, int> p = pair(i, t[j]);
    		handle(p, pair(i, t[j] - 1));
    		handle(p, pair(i + 1, t[j]));
    	}
    	
    	for(int j = sz(t) - 1; j >= 0; --j) {
    		pair<int, int> p = pair(i, t[j]);
    		handle(p, pair(i, t[j] + 1));
    	}
    }
    vector<pair<int, int>> ok(n);
    for(auto val : ind) {
    	ok[val.ss] = pair(ans[val.ff][1], ans[val.ff][2]);
    }
    for(auto val : ok) cout << val.ff << ' ' << val.ss << '\n';
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