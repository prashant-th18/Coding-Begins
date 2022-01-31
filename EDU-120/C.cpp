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
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    sort(v.begin(), v.end());
    ll sum = accumulate(all(v), 0LL);
    if(sum <= k)
    {
        cout << 0; return 0;
    }
    vector<ll> suffix(n, 0);
    suffix[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; --i)
    {
        suffix[i] = suffix[i + 1] + v[i];
    }
    ll maxx = v[0], ans = 1e12;
    maxx = min(maxx, k / (n) + 10);
    for(ll i = maxx; ; --i)
    {
        // set min to i
        // then see how many we have to set to 0 index such that condition is true
        ll temp = sum;
        bool flag = false;
        temp -= (v[0] - i);
        ll cnt = (v[0] - i);
        if(temp <= k)
        {
            flag = true;
        }
        else
        {
            // binary search [1 ... n - 1]
            ll s = 1, e = n - 1;
            ll anss = -1;
            while(s <= e)
            {
                ll mid = (s + e) / 2;
                if(temp - (suffix[mid] - (n - mid) * i) <= k)
                {
                    anss = mid; s = mid + 1;
                }
                else e = mid - 1;
            }
            if(anss != -1)
            {
                cnt += (n - anss);
                flag = true;
            }
        }
        if(flag)
        {
            if(cnt <= ans)
            {
                ans = cnt;
            }
            else break;
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
