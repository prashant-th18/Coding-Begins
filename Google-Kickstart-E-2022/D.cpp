#ifdef LOCAL
	#define _GLIBCXX_DEBUG
	#include "debug.h"
#else
	#include "bits/stdc++.h"
	using namespace std;
	typedef long long ll;
	#define sz(s) ((int)s.size())
	#define all(v) begin(v), end(v)
	#define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
using pll = pair<char, ll>;
using pii = pair<int, int>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct edge {
	bool operator() (const array<ll, 4>& a, const array<ll, 4>& b) const {
		return a[3] > b[3];
	}
};
// *-> KISS*
int solve() {
    ll n, p, m, ar, ac; cin >> n >> p >> m >> ar >> ac;
	--ar; --ac;
	array<pll, 4> dir;
	// North, East, West, South
	for(int i = 0; i < n; ++i) {
		char ch; cin >> ch;
		int t; cin >> t;
		dir[i] = pll(ch, t);
	}
	//
	for (int i = 0; i < p; i++) {
		int a, b, c; cin >> a >> b >> c;
	}
	//
	auto doIt = [&](ll m, ll k) {
		if(k == 0) {
			return m + dir[k].ss;
		}
		else if(k == 1) {
			return m - dir[k].ss;
		}
		else if(k == 2) {
			return m * dir[k].ss;
		}
		else {
			if(m >= 0) {
				return m / dir[k].ss;
			}
			else {
				if(abs(m) % dir[k].ss == 0) {
					return m / dir[k].ss;
				}
				else {
					return m / dir[k].ss - 1;
				}
			}
		}
	};

	for(ll dis = 1; dis <= 20; ++dis) {
		for(ll i = 0; i < n; ++i) {
			for(ll j = 0; j < n; ++j) {
				// I am at [i, j]
				vector<pii> v;
				for(int k = 0; k < n; ++k) {
					for(int l = 0; l < n; ++l) {
						if(abs(i - k) + abs(j - l) == dis) v.push_back(pii(k, l));
					}
				}
				for(int k = 0; k < sz(v); ++k) {
					int p1 = v[i].ff, p2 = v[i].ss;
					set<edge> st;
					vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MIN));
					array<ll, 4> t = {i, j, 0, 0};
					st.insert(t);
					dis[i][j] = 0;
					while(sz(st)) {
						int dx[4] = {-1, 0, 0, 1};
						int dy[4] = {0, 1, -1, 0};
						array<ll, 4> t = *st.begin();
						st.erase(st.begin());
						if(t[3] > dis) {
							continue;
						}
						for(int k = 0; k < 4; ++k) {
							int ni = t[0] + dx[k], nj = t[1] + dy[k];
							if(dis[ni][nj] == LLONG_MIN) {
								dis[ni][nj] = doIt(t[2], k);
								st.insert({ni, nj, dis[ni][nj], t[3] + 1});
							}
							else {
								ll mm = doIt(t[2], k);
								if(mm > dis[ni][nj]) {
									auto it = st.find({ni, nj, dis[ni][nj], t[3]});
									if(it != st.end()) st.erase(it);
									dis[ni][nj] = mm;
									st.insert({ni, nj, mm, t[3] + 1});
								}
							}
						}
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
		cout << "Case #" << i << ": ";
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
