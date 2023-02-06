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
typedef unsigned int uint_t;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// https://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
// this function returns next higher number with same number of set bits as x.
uint_t snoob(uint_t x)
{
 
  uint_t rightOne;
  uint_t nextHigherOneBit;
  uint_t rightOnesPattern;
 
  uint_t next = 0;
 
  if(x)
  {
 
    // right most set bit
    rightOne = x & -(signed)x;
 
    // reset the pattern and set next higher bit
    // left part of x will be here
    nextHigherOneBit = x + rightOne;
 
    // nextHigherOneBit is now part [D] of the above explanation.
 
    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit;
 
    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;
 
    // correction factor
    rightOnesPattern >>= 2;
 
    // rightOnesPattern is now part [A] of the above explanation.
 
    // integrate new pattern (Add [D] and [A])
    next = nextHigherOneBit | rightOnesPattern;
  }
 
  return next;
}
ll cal(string& a, string& b) {
	ll ans = 0;
	ll how = 0;
	for(int i = 0; i < sz(a); ++i) {
		if(a[i] == b[i]) {
			++how;
		}
		else {
			ans += (how * (how + 1) / 2);
			how = 0;
		}
	}
	ans += (how * (how + 1) / 2);
	return ans;
}
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<char> dis;
    for(int i = 0; i < sz(a); ++i) {
    	dis.push_back(a[i]);
    }
    sort(all(dis));
    dis.resize(unique(all(dis)) - dis.begin());
    k = min(k, sz(dis));
    
    ll maxx = 0;
    // Select k from these
    if(k != 0) {
    	int num = 0;
    	while(__builtin_popcount(num) != k) {
    		++num;
    	}
    	vector<char> changed(sz(a), '.');
    	while(1) {
    		set<char> st;
    		int exclude = num;
    		for(int i = 0; i < sz(dis); ++i) {
    			if(num & (1 << i)) {
    				st.insert(dis[i]);
    				exclude ^= (1 << i);
    			}
    		}
    		if(exclude) break;
    		for(int i = 0; i < sz(a); ++i) {
    			if(a[i] != b[i]) {
    				if(st.count(a[i])) {
    					changed[i] = a[i];
    					a[i] = b[i];
    				}
    			}
    		}
    		maxx = max(maxx, cal(a, b));
    		for(int i = 0; i < sz(a); ++i) {
    			if(changed[i] != '.') {
    				a[i] = changed[i];
    				changed[i] = '.';
    			}
    		}
    		num = snoob(num);
    	}
    	cout << maxx;
    }
    else {
    	cout << cal(a, b);
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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