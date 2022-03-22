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
    deque<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto check = [&](int index = 0) 
    {
        string res = "";
        res += v[index];
        res += v[index + 1];
        if(res == "((" || res == "()" || res == "))") return true;
        return false;
    };
    int op = 0;
    while(sz(v) >= 2)
    {
        if(check())
        {
            ++op;
            v.pop_front(); v.pop_front();
        }
        else
        {
            // check till we get ")"
            int index = -1;
            for(int i = 2; i < sz(v); ++i)
            {
                if(v[i] == ')')
                {
                    index = i; break;
                }
            }
            if(index == -1) break;
            else
            {
                while(index >= 0)
                {
                    v.pop_front();
                    --index;
                }
                ++op;
            }
        }
    }
    cout << op << ' ' << sz(v);
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
