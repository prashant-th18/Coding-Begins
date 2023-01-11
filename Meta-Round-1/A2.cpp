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
	vector<int> a(n), b(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = n; i < 2 * n; ++i) b[i] = b[i - n];
	vector<int> lps(n);
	{
		lps[0] = 0;
		int i = 1, len = 0;
		while(i < n)
		{
			if(a[i] == a[len])
			{
				lps[i] = len + 1;
				++i, ++len;
			}
			else
			{
				if(len != 0)
				{
					len = lps[len - 1];
				}
				else
				{
					++i;
				}
			}
		}
	}
	int i = 0, j = 0, maxx = -1e9, shift = 0;
	auto ans = [&]()
	{
		//  j + 1
		int len = j + 1;
		if(len >= maxx)
		{
			if(len == maxx)
				shift = max(shift, i - j);
			else
				shift = i - j;
			maxx = len;
		}
	};
	while(i < n + 1)
	{
		if(b[i] == a[j])
		{
			ans();
			++j;
			++i;
		}
		else
		{
			if(j == 0) ++i;
			else
			{
				j = lps[j - 1];
			}
		}
		if(j == n)
		{
			j = lps[j - 1];
		}
	}
	bool flag = true;
	int ind = shift;
	if(ind == 1) {
		if(n == 2) {
			if(!(k & 1)) flag = false;
		}
	}
	else {
		// OP
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
		cerr << "##################" << '\n';
#endif

		if (solve()) {
			break;
		}
		cout << '\n';
	}
#ifdef LOCAL
	cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
// -> Keep It Simple Stupid!
