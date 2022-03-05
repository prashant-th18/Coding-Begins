#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
int N = 1e6;
vector<ll> primes;
vector<bool> v;
// *-> KISS*
int solve() {
    int n; cin >> n;
    map<ll, ll> mp;
    vector<ll> ans;
    for (int i = 0; i < n; i++) {
        ll tt; cin >> tt;
        ans.push_back(tt);
        for(ll & val : primes)
        {
            if(val * val > tt) break;
            ll c = 0;

            while(tt % val == 0) ++c, tt /= val;

            if(c != 0)
            {
                mp[val]++;
            }
        }
        if(tt >= 2) mp[tt]++;
    }
    ll ubound = (2 * n + 2) / 3;
    int change = 0;
    bool flag = false;
    for(const auto& val : mp)
    {
        // n - val.ss <= ubound CORRECT
        if(n - val.ss <= ubound)
        {
            for(ll i = 0; i < n; ++i)
            {
                if(ans[i] % val.ff != 0)
                {
                    ++change;
                    ans[i] = val.ff;
                }
            }
            flag = true;
            break;
        }
    }
    assert(flag);
    for(auto val : ans) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    v.assign(N, true);
    v[1] = v[0] = false;
    for(int i = 4; i < N; i += 2) v[i] = false;
    primes.push_back(2);
    for(ll i = 3; i < N; i += 2)
    {
        if(v[i])
        {
            primes.push_back(i);
            for(ll j = i * i; j < N; j += 2 * i) v[j] = false;
        }
    }
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!
