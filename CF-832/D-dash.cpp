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
	int n, q; cin >> n >> q;
	vector<int> v(n);
	vector<int> pre(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		if(i == 0) pre[i] = v[i];
		else pre[i] = pre[i - 1] ^ v[i];
	}
	map<int, vector<int>> odd, even;
	for(int i = 0; i < n; ++i) {
		if(i & 1) {
			odd[pre[i]].push_back(i);
		}
		else {
			even[pre[i]].push_back(i);
		}
	}
	vector<int> zero(n);
	for(int i = 0; i < n; ++i) {
		if(i == 0) zero[i] = (v[i] == 0);
		else {
			zero[i] = zero[i - 1] + (v[i] == 0);
		}
	}
	while(q--) {
		int a, b; cin >> a >> b;
		--a, --b;
		int last = (a == 0) ? (0) : (pre[a - 1]);
		if((pre[b] ^ last) != 0) cout << -1;
		else {
			int len = b - a, zz = (a == 0) ? (0) : (zero[a - 1]);
			if(zero[b] - zz == len + 1) cout << 0;
			else {
				if(len % 2 == 0) cout << 1;
				else {
					if(v[a] == 0 || v[b] == 0) cout << 1;
					else {
						int x = last;
						bool flag = false;
						if(a % 2 == 1) {
							vector<int>& o = odd[x];
							int lw = lower_bound(all(o), a) - begin(o);
							if(lw != odd[x].size() && odd[x][lw] <= b) flag = true;
						}
						else {
							vector<int>& e = even[x];
							int lw = lower_bound(all(e), a) - begin(e);
							if(lw != e.size() && e[lw] <= b) flag = true;
						}
						if(flag) cout << 2;
						else cout << -1;

					}
				}
			}
		}
		cout << '\n';
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
