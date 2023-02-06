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

const int M = 1e5 + 10;
vector<vector<int>> fac;
void init() {
	fac.assign(M + 1, vector<int>());
	for(int i = 1; i <= M; ++i) {
		for(int j = i; j <= M; j += i) {
			fac[j].push_back(i);
		}
	}
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
    	cin >> v[i];
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    n = sz(v);
    
   	// n, m
   	// v
   	const int maxx = M + 1;
   	vector<int> ans(m + 1, 0);
   	set<int> st;
   	for(int i = 0; i < m; ++i) st.insert(i + 1);
   	
   	// 0 Based
   		
   	int i = 0, j = 0;
   	while(!st.empty() && j < n) {
   		int num = v[j];
   		vector<int>& t = fac[num];
   		for(const auto& val : t) {
   			if(val > m) break;
   			if(ans[val] == 0) {
   				st.erase(val);
   				ans[val]++;
   			}
   			else ++ans[val];
   		}
   		++j;
   	}
   	if(!st.empty()) {
   		cout << -1;
   		return 0;
   	}
   	int minn = 1e9;
   	while(j <= n) {
   		if(st.empty()) {
   			minn = min(minn, v[j - 1] - v[i]);
	   		
	   		// Erase "i"
	   		int num = v[i];
	   		vector<int>& t = fac[num];
	   		for(const auto& val : t) {
	   			if(val > m) break;
	   			
	   			if(ans[val] == 1) {
	   				st.insert(val);
	   			}
	   			--ans[val];
	   		}
	   		++i;
   		}
   		else {
   			if(j == n) break;
   			// Consider the current "j"
   			int num = v[j];
   			vector<int>& t = fac[num];
   			for(const auto& val : t) {
	   			if(val > m) break;
	   			
	   			if(ans[val] == 0) {
	   				st.erase(val);
	   			}
	   			++ans[val];
	   		}
	   		++j;
	   		if(st.empty()) {
	   			minn = min(minn, v[j - 1] - v[i]);
	   		}
   		}
   	}
   	if(st.empty()) {
   		minn = min(minn, v[n - 1] - v[i]);
   	}
   	cout << minn;
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
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