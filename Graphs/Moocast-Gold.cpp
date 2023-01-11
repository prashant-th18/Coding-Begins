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
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct custom {
	ll dis, a, b;

	bool operator<(const custom& other) const {
		if(dis != other.dis)
			return dis < other.dis;

		return make_pair(a, b) < make_pair(other.a, other.b);
	}
};
// *-> KISS*
int solve() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
    int n; cin >> n;
	vector<pll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].ff >> v[i].ss;
	/* set<custom> st; */
	vector<array<ll, 3>> st;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ll d1 = (v[i].ff - v[j].ff) * (v[i].ff - v[j].ff);
			ll d2 = (v[i].ss - v[j].ss) * (v[i].ss - v[j].ss);
			st.push_back({d1 + d2, i, j});
		}
	}
	sort(all(st), [&](array<ll, 3>& a, array<ll, 3>& b) {
			return a[0] < b[0];
			});
	vector<int> rank(n, 1);
	vector<int> par(n, -1);

	auto find = [&](int node) {
		vector<int> t;
		while(par[node] > 0) {
			t.push_back(node);
			node = par[node];
		}
		for(auto val : t) par[val] = node;
		return node;
	};

	auto un = [&](int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		
		if(rank[a] > rank[b]) {
			rank[a] += rank[b];
			par[b] = a;
		}
		else {
			par[a] = b; 
			rank[b] += rank[a];
		}
	};

	for(auto& val : st) {
		ll d = val[0], a = val[1], b = val[2];
		un(a, b);
		if(rank[find(a)] == n) {
			cout << d; return 0;
		}
	}
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
