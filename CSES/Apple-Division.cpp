#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    ll min_diff = 1e12;
    for(int i = 0; i < ((1LL << n) - 1); ++i)
    {
        // set bits go to one set
        // unset to another
        ll s1 = 0, s2 = 0;
        for (int j = 0; j < n; j++) {
            if(i & (1LL << j)) s1 += v[j];
            else s2 += v[j];
        }
        min_diff = min(min_diff, abs(s1 - s2));
    }
    cout << min_diff;
    return 0;
}
// -> Keep It Simple Stupid!
