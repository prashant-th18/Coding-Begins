#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    ll k, s, ans {}; cin >> k >> s;
    for (int i = 0; i <= k; i++) {
        ll t = s - i;
        if(t < 0) break;
        if(t > 2 * k)
        {
            continue;
        }
        else
        {
            for (int j = 0; j <= k; j++) {
                if(t - j <= k && t - j >= 0) ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
