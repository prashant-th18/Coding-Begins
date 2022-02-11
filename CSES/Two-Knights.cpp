#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    ll n; cin >> n;
    for(ll i = 1; i <= n; ++i)
    {
        cout << (i - 1) * (i + 4) / 2 * (i * i - 3 * i + 4) << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
