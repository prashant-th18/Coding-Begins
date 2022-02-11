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
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        vector<ll> v = {0, 360};
        int n; cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            v.push_back((a + sum) % 360);
            sum += a;
        }
        sort(v.begin(), v.end());
        ll maxxdiff = 0;
        for(int i = 1; i < sz(v); ++i)
        {
            maxxdiff = max(maxxdiff, v[i] - v[i - 1]);
        }
        cout << maxxdiff;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
