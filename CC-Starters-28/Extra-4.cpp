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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        // X / x1 * y1       X / x2 * y2
        int a = x1 * y2, b = x2 * y1;
        if(a > b) cout << -1;
        else if(a == b) cout << 0;
        else cout << 1;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
