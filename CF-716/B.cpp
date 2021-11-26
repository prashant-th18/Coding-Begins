#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll binexp(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power & 1)
        {
            res = res % MOD * base % MOD;
        }
        base = base % MOD * base % MOD;
        power >>= 1;
    }
    return res;
}
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, k; cin >> n >> k;
        cout << binexp(n, k) << '\n';
    }
    return 0;
}
