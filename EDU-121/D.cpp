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

// *-> KISS*
int solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = 1e18;
    sort(v.begin(), v.end());
    for(ll i = 0; i < (1LL << 32); ((i == 0) ? (i++) : (i *= 2)))
    {
        // i, j, k means participants
        if(i >= n)
        {
            ans = min(ans, i + 2 - n); break;
        }
        if(i != 0)
        {
            ll index = i - 1;
            if(v[index] == v[index + 1])
            {
                continue;
            }
            else
            {
            }
        }
        for(ll j = 0; j < (1LL << 32); ((j == 0) ? (j++) : (j *= 2)))
        {
            if(i + j >= n)
            {
                ll a1 = (i == 0) ? (1) : (i);
                ll a2 = (j == 0) ? (1) : (j);
                ans = min(ans, a1 + a2 + 1 - n); break;
            }
            if(j != 0)
            {
                ll indexx = i + j - 1;
                if(v[indexx] == v[indexx + 1]) continue;
                else
                {
                }
            }
            for(ll k = 0; k < (1LL << 32); ((k == 0) ? (k++) : (k *= 2)))
            {
                if(i + j + k >= n)
                {
                    ll a1 = (i == 0) ? (1) : (i);
                    ll a2 = (j == 0) ? (1) : (j);
                    ll a3 = (k == 0) ? (1) : (k);
                    ans = min(ans, a1 + a2 + a3 - n);
                    cout << i << ' ' << j << ' ' << k << endl;
                }
                /*
                if(k != 0)
                {
                    ll ind = i + j + k - 1;
                    if(v[ind] == v[ind + 1]) continue;
                    else
                    {
                        pot += k;
                    }
                }
                else
                {
                    pot++;
                }
                if(pot >= n)
                ans = min(ans, pot - n);
                */
            }
        }
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
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
}
// -> Keep It Simple Stupid!
