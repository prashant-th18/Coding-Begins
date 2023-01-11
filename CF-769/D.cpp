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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
	if(s == e) t[in] = v[s];
	else {
		int mid = (s + e) >> 1;
		build(2 * in, s, mid);
		build(2 * in + 1, mid + 1, e);
		t[in] = gcd(t[2 * in], t[2 * in + 1]);
	}
}
int query(int in, int s, int e, int qs, int qe) {
	if(qs > qe) return 0;
	if(s == qs && e == qe) return t[in];
	int mid = midpoint(s, e);
	return gcd(query(2 * in, s, mid, qs, min(qe, mid)), query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
// *-> KISS*
int solve() {
	cin >> n;
	v.assign(n, 0);
	t.assign(4 * n, 0);
	for(int i = 0; i < n; ++i) cin >> v[i];
	build();
	int pre = -1;
	vector<int> ans(n, 0);
	for(int i = 0; i < n; ++i) {
		ans[i] += i == 0 ? 0 : ans[i - 1];
		if(v[i] == 1) {
			ans[i]++;
		}
		else {
			int s = pre + 1, e = i;
			while(s <= e) {
				int mid = (s + e) >> 1;
				int gg = query(1, 0, n - 1, mid, i);
				if(gg == i - mid + 1) {
					pre = i;
					++ans[i];
					break;
				}
				else if(gg > i - mid + 1) {
					e = mid - 1;
				}
				else s = mid + 1;
			}
		}
		cout << ans[i] << ' ';
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
