#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    ll n, k; cin >> n >> k;
    vector<ll> v(k);
    ll sum {};
    for (ll &val : v) {
        cin >> val;
        sum += val;
    }
    ll c = n / sum * k;
    n = max(0, n - (n / sum) * sum);
    for(ll i = 0; i < k && n > 0; ++i)
    {
        n -= v[i];
        c++;
    }
    cout << c;
    return 0;
}
// -> Keep It Simple Stupid!
