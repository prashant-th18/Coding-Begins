#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 998244353;
// *-> KISS*
ll ans = 1;
unordered_map<ll, ll> mp;
ll call(ll num)
{
    if(mp.count(num)) return mp[num];
    return mp[num] = call(num / 2) % MOD * call((num + 1) / 2) % MOD;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    mp[1] = 1; mp[2] = 2; mp[3] = 3; mp[4] = 4;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll x; cin >> x;
        cout << call(x);
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
