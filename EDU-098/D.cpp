#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const ll MOD = 998244353;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        base %= MOD;
        while(power)
        {
            if(power & 1)
            {
                res = res * base % MOD;
            }
            base = base * base % MOD;
            power >>= 1;
        }
        return res;
    };
    for(int t_ = 0; t_ < test; t_++)
    {
        ll n; cin >> n;
        vector<ll> fib(n + 1);
        fib[1] = 1, fib[2] = 1;
        for(int i = 3; i <= n; ++i)
        {
            fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        }
        ll num = binexp(2, n);
        cout << (fib[n] * binexp(num, MOD - 2)) % MOD;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
