#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v(n);
    ordered_set st1, st2;
    for (ll &val : v) {
        cin >> val;
        st2.insert(val);
    }
    st1.insert(v[0]);
    st2.erase(st2.upper_bound(v[0]));
    ll mini = LLONG_MAX; ll index = -1; ll which = -1;
    auto fun = [&](ll num, ll op, ll ind) -> void
    {
        if(num < mini)
        {
            num = mini;
            index = ind;
            which = op;
        }
    };
    for(int i = 1; i <= n; ++i)
    {
        // 0 -> left -> max right -> max
        // 1 -> left -> max right -> min
        // 2 -> left -> min right -> max
        st2.erase(st2.find(v[i]));
        ll num1 = st1.order_of_key(v[i]), num2 = st2.order_of_key(v[i]);
        ll num3 = sz(st1) - st1.order_of_key(*st1.lower_bound(v[i]));
        ll num4 = sz(st2) - st2.order_of_key(*st2.lower_bound(v[i]));
        ll op1 = num1 + num2;
        ll op2 = num1 + num4;
        ll op3 = num3 + num2;
        ll maxx = min({op1, op2, op3});
        if(maxx == op1)
        {
            fun(op1, 0, i);
        }
        else if(maxx == op2)
        {
            fun(op2, 1, i);
        }
        else
        {
            fun(op3, 2, i);
        }
        st1.insert(v[i]);
    }
    vector<ll> temp = v;
    int cnt = 0;
    if(index != -1)
    {
        for(int i = index - 1; i >= 0; --i)
        {
            if(which == 0)
            {
                if(v[i] < v[i + 1])
                {
                    ++cnt; v[i] = v[i + 1];
                }
            }
            else
            {
                if(v[i] > v[i + 1])
                {
                    ++cnt; v[i] = v[i + 1];
                }
            }
        }
        for(int i = index + 1; i < n; ++i)
        {
            if(which == 0 || which == 2)
            {
                if(v[i] < v[i - 1])
                {
                    ++cnt;
                    v[i] = v[i - 1];
                }
            }
            else 
            {
                if(v[i] > v[i - 1])
                {
                    ++cnt;
                    v[i] = v[i - 1];
                }
            }
        }
    }
    bool flag = true;
    for(int i = 1; i < n - 1; ++i)
    {
        if(v[i] > v[i - 1] && v[i] > v[i + 1])
        {
            flag = false; break;
        }
    }
    if(flag)
    {
        v = temp; cnt = 0;
    }
    cout << cnt << '\n';
    for(ll val : v) cout << val << ' ';
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
