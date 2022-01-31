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

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

// *-> KISS*
int solve() {
    int h, m, n; cin >> h >> m >> n;
    vector<pair<int, int>> index(h);
    vector<bool> vis(h, false);
    int k = 0;
    vector<ordered_set> v;
    vector<int> mysize;
    for(int i = 0; i < h; ++i)
    {
        if(vis[i]) continue;
        else
        {
            ordered_set temp;
            int j = i, cnt = 0;
            while(vis[j] == false)
            {
                vis[j] = true;
                index[j] = pair(k, cnt);
                temp.insert(cnt++);
                j += m;
                j %= h;
            }
            v.push_back(temp);
            mysize.push_back(sz(temp));
            ++k;
        }
    }
    ll ans = 0;
    unordered_map<int, pair<int, int>> mp; // it will be used to store what is the index where our value is stored
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        if(ch == '+')
        {
            int value, initial;
            cin >> value >> initial;
            int what_index = index[initial].ff;
            int cc = index[initial].ss;
            auto& temp = v[what_index];
            // temp is the ordered_set
            auto it = temp.lower_bound(cc);
            if(it != temp.end())
            {
                ans += (*it - cc);
                mp[value] = pair(*it, what_index);
                temp.erase(it);
            }
            else
            {
                ans += (mysize[what_index] - cc);
                it = temp.begin();
                ans += (*it);
                mp[value] = pair(*it, what_index);
                temp.erase(it);
            }
        }
        else
        {
            int value; cin >> value;
            v[mp[value].ss].insert(mp[value].ff);
        }
    }
    cout << ans;
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
