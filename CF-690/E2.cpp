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

const int N = 2e5 + 1;
vector<ll> f(N, 1);
template<typename T>
T binexp(T a, T b) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1LL * ans * a % MOD;
		}
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return ans;
}
void fact() {
	for(ll i = 2; i < N; ++i) {
		f[i] = i * f[i - 1] % MOD;
	}
}
ll inv(ll n) {
	return binexp(n, (ll)MOD - 2);
}
ll ncr(ll n, ll r) {
	if(r > n) return 0;
	return f[n] * inv(f[r]) % MOD * inv(f[n - r]) % MOD;
}
// *-> KISS*
int solve() {
	ll n, m, k; cin >> n >> m >> k;
	vector<int> freq(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		freq[t]++;
	}
	vector<ll> pre(n + 1, 0);
	for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + freq[i];
	ll ans = 0;
	for(ll i = 1; i <= n; ++i) {
		ll maxx = min(n, i + k);
		ll elem1 = pre[maxx] - pre[i - 1];
		ll elem2 = pre[maxx] - pre[i];

		ll elem = (ncr(elem1, m) - ncr(elem2, m) + MOD) % MOD;
		ans = (ans + elem) % MOD;
	}
	cout << ans;
	return 0;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fact();
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
