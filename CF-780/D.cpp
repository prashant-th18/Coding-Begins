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
const int MOD = 1000000007;
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
    int n; cin >> n;
    vector<ll> v(n);
    vector<ll> neg(n + 1, 0), two(n + 1, 0);
    for(int i = 0; i < n; ++i) { 
        cin >> v[i];
        neg[i + 1] = neg[i] + (v[i] < 0);
        two[i + 1] = two[i] + (abs(v[i]) == 2);
        if(v[i] == 0) zero.push_back(i);
    }
    ll cnt = INT_MAX;
    vector<ll> rev = v;
    for(int i = 0; i < n; ++i)
    {
        if(v[i] < 0) cnt = 0;
        else ++cnt;
        rev[i] = cnt;
    }
    // index
    // [0, n - index]
    int ans = -1, x = n, y = 0;
    // Not deleting anything from left
    auto check = [&](int a, int b)
    {
        if(two[a + 1] - two[b + 1] > ans)
        {
            ans = two[a + 1] - two[b + 1];
            x = b; y = n - 1 - a;
        }
    };
    if(sz(zero) != 0)
    {
        
    }
    else
    {
        
    }
    for(int i = 1; i <= n; ++i)
    {
        int how = neg[n] - neg[i];
        auto ind = lower_bound(all(zero), i) - begin(zero);
        if(v[i - 1] == 0)
        {
            if(0 > ans)
            {
                ans = 0;
                x = i, y = 0;
            }
            continue;
        }
        if(ind == sz(zero))
        {
            
        }
        else
        {
            int how = neg[zero[ind]] - neg[i];
            if(how % 2 == 0)
            {
                check(zero[ind] - 1, i);
            }
            else
            {
                int zindex = zero[ind];
                if(rev[zindex] >= )
                {
                    
                }
                zindex -= rev[zindex];
            }
        }
    }
    cout << x << ' ' << y;
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
    return 0;
}
// -> Keep It Simple Stupid!
