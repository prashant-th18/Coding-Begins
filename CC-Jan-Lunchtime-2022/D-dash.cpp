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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto dec = [&](int& t) -> void
    {
       t = (t - 1 + n) % n;  
    };
    int cnt = 1;
    // cnt > n all done!
    auto find_zero = [&]()
    {
        for(int i = 0; i < n; ++i)
        {
            if(v[i] == 0)
            {
                int j = i;
                int c = 0;
                bool flag = true;
                while(c < k)
                {
                    dec(j);
                    if(v[j] == 0)
                    {
                        flag = false; break;
                    }
                    ++c;
                }
                if(flag) return i;
            }
        }
        return -1;
    };
    int t = find_zero();
    vector<int> ans(n);
    while(t != -1)
    {
        int c = 0;
        int last = t;
        while(c < k)
        {
            dec(t);
            --v[t];
            ++c;
        }
        v[last] = -1;
        ans[last] = cnt++;
        t = find_zero();
    }
    if(cnt <= n) cout << -1;
    else
    {
        for(auto val : ans) cout << val << ' ';
    }
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
