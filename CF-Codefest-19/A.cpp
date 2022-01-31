#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
// *-> KISS*
int32_t main() {
    int t; cin >> t;
    while(t--) {
    ll a, b, n; cin >> a >> b >> n;
    vector<ll> v = {a, b, a ^ b};
    n %= 3;
    cout << v[n] << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
