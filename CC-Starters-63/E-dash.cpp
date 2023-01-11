#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int inf = (int)1e9;
const int K = 26;
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
int n;
vector<ll> v;
/* void build(int in, int s, int e) { */
/* 	if(s == e) t[in] = v[s]; */
/* 	else { */
/* 		int mid = (s + e) >> 1; */
/* 		build(2 * in, s, mid); */
/* 		build(2 * in + 1, mid + 1, e); */
/* 		t[in] = max(t[2 * in], t[2 * in + 1]); */
/* 	} */
/* } */
/* int query(int in, int s, int e, int qs, int qe) { */
/* 	if(qs > qe) return INT_MIN; */
/* 	if(s == qs && e == qe) return t[in]; */
/* 	int mid = (s + e) >> 1; */
/* 	return max(query(2 * in, s, mid, qs, min(qe, mid)), */ 
/* 			query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe)); */
/* } */

vector<ll> t;
void update(int in, int s, int e, int qs, int qe, ll val) {
	if(qs > qe) return;

	if(s == qs && e == qe) {
		t[in] = add(t[in], val);
	}
	else {
		int mid = (s + e) >> 1;
		update(2 * in, s, mid, qs, min(qe, mid), val);
		update(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, val);
	}
}
ll query1(int in, int s, int e, int qs, int qe) {
	if(qs > qe) return 0;
	if(s == qs && e == qe) return t[in];
	
	int mid = (s + e) >> 1;
	return add(t[in], add(query1(2 * in, s, mid, qs, min(mid, qe)), query1(2 * in + 1, mid + 1, e, 
					max(qs, mid + 1), qe)));
}
// *-> KISS*
int solve() {
    cin >> n;
	v.assign(n, 0);
	t.assign(4 * n + 4, 0);
	vector<int> mp(n + 1, 0); // mp tells indices
	for(int i = 0; i < n; ++i) cin >> v[i], mp[v[i]] = i;
	int lg[n + 1];
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i/2] + 1;

	vector<vector<ll>> st(K + 1, vector<ll>(n + 1, inf));

	for(int i = 1; i <= K; ++i) {
		for(int j = 0; j + (1 << i) <= n; ++j) {
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}

	auto query = [&](int l, int r) {
		int i = lg[r - l + 1];
		return max(st[i][l], st[i][r - (1 << i)+ 1]);
	};
	
	vector<ll> last(n);
	// tells that [last[i] .. i] is sorted
	ll dec = 0;
	for(int i = 1; i < n; ++i) {
		if(v[i] < v[i - 1]) dec = i;
		last[i] = dec;
	}
	vector<ll> dp(n + 1, 0);
	dp[n] = 1;
	update(1, 0, n, n, n, 1);
	ll addTill = n, toAdd = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(addTill <= i) {
			dp[i] = add(dp[i], toAdd);
		}
		int ans = n, s = i + 1, e = n - 1;
		while(s <= e) {
			int mid = (s + e) >> 1;
			int maybe = query(i + 1, mid);
			if(maybe > v[i]) {
				ans = mid; e = mid - 1;
			}
			else s = mid + 1;
		}
		ll value = query1(1, 0, n, i + 1, ans);
		cout << value << endl;
		dp[i] = add(dp[i], value);
		if(addTill >= i) {
			addTill = last[i];
			toAdd = dp[i];
		}
		else toAdd = add(toAdd, dp[i]);
		
		update(1, 0, n, i, i, dp[i]);
	}
	cout << dp[0];
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
