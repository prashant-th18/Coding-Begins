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

// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
	string s; cin >> s;
	priority_queue<int> pq;
	{
		map<char, int> mp;
		for(int i = 0; i < n; ++i) mp[s[i]]++;
		for(auto& val : mp) pq.push(val.ss);
	}
	int maxx = 1;
	for(int len = 2; len <= n; ++len) {
		int l = k % len;
		priority_queue<int> t = pq, here;
		vector<bool> vis(len, false);
		for(int i = 0; i < len; ++i) {
			int j = i, c = 0;
			while(!vis[j]) {
				vis[j] = true;
				++c;
				j += l;
				j %= len;
			}
			if(c != 0) here.push(c);
		}
		bool f = true;
		while(!t.empty() && !here.empty()) {
			int t1 = t.top(); t.pop();
			int t2 = here.top(); here.pop();
			if(t1 < t2) {
				f = false;
				break;
			}
			else if(t1 > t2) {
				t.push(t1 - t2);
			}
		}
		if(f && here.empty()) {
			maxx = len;
		}
	}
	cout << maxx;
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
