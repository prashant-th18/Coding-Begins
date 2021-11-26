#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int i = 0; i < tt; ++i)
    {
    ll n; cin >> n;
    cout << (1LL + (n - 1) / 2);
    cout << '\n';
    }
    return 0;
}
