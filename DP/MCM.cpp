#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	--n;
	vector<vector<int>> m(n + 1, vector<int>(n + 1));
	decltype(m) s(n + 1, vector<int>(n + 1));
	for(int i = 0; i < n; ++i) {
		m[i + 1][i + 1] = 0;
	}

	for(int l = 2; l <= n; ++l) {
		for(int i = 1; i <= n - l + 1; ++i) {
			int j = i + l - 1;
			m[i][j] = 1e9;
			for(int k = i; k <= j - 1; ++k) {
				int q = m[i][k] + m[k + 1][j] + v[i - 1] * v[k] * v[j];
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m[1][n];
	return 0;
}
// -> Keep It Simple Stupid!
