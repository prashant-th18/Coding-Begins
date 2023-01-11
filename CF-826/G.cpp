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

const int inf = (int)1e9;
int n, m, f, k;
unordered_map<int, int, custom_hash> car, non;
vector<vector<int>> v;
vector<int> dp, dis;
struct edge {
	int dis, node, val;

};
// *-> KISS*
int solve() {
    cin >> n >> m;
	v.assign(n + 1, vector<int>());
	dp.assign(n + 1, -1);
	dis.assign(n + 1, inf);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> f;
	for(int i = 0; i < f; ++i) {
		int t; cin >> t;
		car[t]++;
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		int t; cin >> t;
		non[t]++;
	}
	queue<edge> st;
	st.push({0, 1, non[1]});
	dp[1] = non[1];
	dis[1] = 0;
	int minn = f;
	while(!st.empty()) {
		edge t = st.front();
		st.pop();
		if(car[t.node] != 0 && non[t.node] == 0) minn = min(minn, f - t.val);
		int node = t.node, value = t.val, dist = t.dis;
		for(int val : v[node]) {
			if(dis[val] < dist + 1) {
				continue;
			}
			else if(((dis[val] == dist + 1) && (dp[val] < value + non[val])) || (dis[val] > dist + 1))  {
				int nval = value + non[val];
				if(dp[val] < nval) {
					st.push({dist + 1, val, nval});
					dp[val] = nval;
				}
				dis[val] = dist + 1;
			}
		}
	}
	cout << minn;
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
