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
    vector<int> color(256, -1);
    // color se aage nhi bdna hai
    // color se piche hi dhundna hai
    // let say color -> c
    // c - 1, c - 2, c - 3, ... 
    // agr c - i visited milta hai toh c - i ke group ka size pucha jaaega, agr uska size != k hai, and
    // c - (c - i) itne aa skte hai us group mai agr
    // toh hm isko us group mai mila denge
    // agr visited milne se pehle, hi hmare group ka size k ho jaata hai toh minimum ko bol dia jaaega
    
    // -1 -> Unvisited
    // non-negative -> visited
    color[0] = 0;
    vector<int> count(256, 0);
    count[0] = 1;
    vector<int> ans(n);
    for(int i = 0; i < n; ++i)
    {
        int tt; cin >> tt;
        if(color[tt] != -1)
        {
            ans[i] = color[tt];
        }
        else
        {
            int j = tt - 1, temp = k - 1;
            while(temp > 0)
            {
                if(color[j] != -1)
                {
                    int cc = count[j];
                    // tt - j
                    if(cc + tt - j <= k)
                    {
                        color[tt] = color[j];
                        count[tt] = cc + tt - j;
                    }
                    else
                    {
                        ++j;
                        color[tt] = j;
                        count[tt] = tt - j + 1;
                    }
                    for(int z = tt - 1; z >= j; --z) color[z] = color[tt], count[z] = count[tt];
                    break;
                }
                --j;
                --temp;
            }
            if(color[tt] == -1)
            {
                color[tt] = tt - k + 1;
                count[tt] = k;
                for(int z = tt - 1; z >= tt - k + 1; --z) color[z] = color[tt], count[z] = count[tt];
            }
            ans[i] = color[tt];
        }
    }
    for(auto val : ans) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
