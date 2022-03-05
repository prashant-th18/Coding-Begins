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
vector<ll> fact;
// *-> KISS*
int solve() {
    ll n; cin >> n;
    int minn = INT_MAX;
    for(int i = 0, cnt = 0; i < (1 << sz(fact)); ++i, cnt = 0)
    {
        ll s = 0;
        for(int j = 0; j < sz(fact); ++j)
        {
            if((1LL << j) & i)
            {
                s += fact[j];
                ++cnt;
            }
        }
        if(s > n) continue;
        else if(s == n)
        {
            minn = min(minn, cnt);
        }
        else
        {
            minn = min(minn, cnt + (__builtin_popcountll(n - s)));
        }
    }
    cout << minn;
    return 0;
}
void pre()
{
    ll ans = 1;
    for(ll i = 1; ; ++i)
    {
        ans *= i;
        if(i <= 2) continue;
        if(ans > (ll)1e14) break;
        fact.push_back(ans);
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    pre();
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
