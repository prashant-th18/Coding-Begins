#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cout << test << endl;
	int n = 2e5;
	string s = string(n, 'a');
	s[n - 1] = 'z';
	for(int i = 1; i < n - 1; ++i) s[i] = (char)(uid(0, 25) + 'a');
	cout << s << endl;
	return 0;
}
// -> Keep It Simple Stupid!
