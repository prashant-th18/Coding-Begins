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

using pii = pair<int, int>;
// *-> KISS*
int solve() {
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pii>> v(n + 1);
    for(int i = 0; i < m; ++i) {
    	int a, b, c; cin >> a >> b >> c;
    	v[a].push_back({b, c});
    	v[b].push_back({a, c});
    }
    vector<int> dist(n + 1, 1e9);
    int l; cin >> l;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
    	pii p = pq.top(); pq.pop();
    	
    	int node = p.ss, dis = p.ff;
    	
    	if(dist[node] < dis) continue;
    	
    	for(const auto& [val, w] : v[node]) {
    		int ndis = dis + w;
			if(dist[val] > ndis) {
				pq.push({ndis, val});
				dist[val] = ndis;
			}
		}
    }
    int ans = 0, rem = 0;
    for(int i = 1; i <= n; ++i) {
    	if(dist[i] == l) ++ans;
    	else if(dist[i] > l) continue;
    	else {
    		for(const auto& [val, w] : v[i]) {
    			if(dist[i] + w == l) continue;
    			else if(dist[i] + w < l) continue;
    			else {
    				int ex = l - dist[i];
    				if(dist[val] + (w - ex) > l) ++ans;
    				else if(dist[val] + w - ex == l) ++ans, ++rem;
    			}
    		}
    	}
    }
    cout << ans - rem / 2;
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