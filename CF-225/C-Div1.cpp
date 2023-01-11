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

int n, m, timer = 1;
vector<vector<int>> v;
vector<int> value;
vector<int> inti, out;
vector<bool> vis;
void dfs(int node) {
	vis[node] = true;
	inti[node] = timer++;
	for(int& val : v[node]) {
		if(!vis[val]) {
			dfs(val);
		}
	}
	out[node] = timer++;
}
vector<int> odd, even, opush, epush;
void p(int in, vector<int>& t, vector<int>& push) {
	t[2 * in] += push[in];
	push[2 * in] += push[in];
	t[2 * in + 1] += push[in];
	push[2 * in + 1] += push[in];
	push[in] = 0;
}
int query(vector<int>& t, vector<int>& push, int in, int s, int e, int pos) {
	if(s == e) return t[in];
	p(in, t, push);
	int mid = (s + e) >> 1;
	if(pos <= mid) return query(t, push, 2 * in, s, mid, pos);
	else return query(t, push, 2 * in + 1, mid + 1, e, pos);
}
void update(vector<int>& t, vector<int>& push, int in, int s, int e, int qs, int qe, int add) {
	if(qs > qe) return;

	if(s == qs && e == qe) {
		t[in] += add;
		push[in] += add;
	}
	else {
		p(in, t, push);
		int mid = (s + e) >> 1;
		update(t, push, 2 * in, s, mid, qs, min(mid, qe), add);
		update(t, push, 2 * in + 1, mid + 1, e, max(qs, mid + 1), qe, add);
	}
}
// *-> KISS*
int solve() {
	cin >> n >> m;
	v.assign(n + 1, vector<int>());
	value.assign(n + 1, 0);
	vis.assign(n + 1, false);
	inti.assign(n + 1, 0);
	out.assign(n + 1, 0);
	for(int i = 0; i < n; ++i) cin >> value[i + 1];
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	odd.assign(16 * n + 1, 0);
	even = opush = epush = odd;
	dfs(1);
	while(m--) {
		int type; cin >> type;
		if(type == 1) {
			ll x, val; cin >> x >> val;
			int l = inti[x], r = out[x];
			/* cerr << l << ' ' << r << endl; */
			if(l & 1) {
				update(odd, opush, 1, 0, timer - 1, l, r, val);
				update(even, epush, 1, 0, timer - 1, l, r, -val);
			}
			else {
				update(odd, opush, 1, 0, timer - 1, l, r, -val);
				update(even, epush, 1, 0, timer - 1, l, r, val);
			}
		}
		else {
			ll x; cin >> x;
			ll val = value[x];
			x = inti[x];
			/* cerr << "Value is: " << val << endl; */
			if(x & 1) {
				cout << val + query(odd, opush, 1, 0, timer - 1, x);
			}
			else cout << val + query(even, epush, 1, 0, timer - 1, x);
			cout << '\n';
		}
		/* cerr << "OK\n"; */
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
