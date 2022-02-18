#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
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

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
int wx, wy;
class type
{
    public:
    char ch;
    ll x, y;
};
// *-> KISS*
int solve() {
    ll n; cin >> n;
    cin >> wx >> wy;
    vector<type> v(n);
    for (int i = 0; i < n; i++) {
        char ch; ll a, b; cin >> ch >> a >> b;
        v[i] = type(ch, a, b);
    }
    auto f = [&](const type& a,const type& b) -> bool
    {
        ll dis1 = abs(a.x - wx) + abs(a.y - wy);
        ll dis2 = abs(b.x - wx) + abs(b.y - wy);
        return dis1 < dis2;
    };

    // x -> i
    // y -> j
    sort(v.begin(), v.end(), f);
    vector<string> perm = {"UU", "UR", "RR", "DR", "DD", "DL", "LL", "UL"};
    unordered_map<string, bool> mp;
    for (int i = 0; i < n; i++) {
        string res = ""; // Up/Down - Right/Left
        if(v[i].x != wx && v[i].y != wy && (abs(v[i].x - wx) % abs(v[i].y - wy) == 0))
        {
            if(v[i].x < wx) res += "U";
            else res += "D";
            if(v[i].y > wy) res += "R";
            else res += "L";
        }
        else if(v[i].x != wx && v[i].y == wy)
        {
            // v[i].y == wy
            if(v[i].x < wx) res += "UU";
            else res += "DD";
        }
        else if(v[i].y != wy && v[i].x == wx)
        {
            if(v[i].y > wy) res += "RR";
            else res += "LL";
        }
        if(res == "") continue;
        
        if(v[i].ch == 'R' || v[i].ch == 'Q')
        {
            for(int j = 0; j < 8; j += 2) {
                if(perm[j] != res) continue;
                if(mp.count(res)) continue;
                else
                {
                    cout << "YES"; return 0;
                }
            }
        }
        if(v[i].ch == 'B' || v[i].ch == 'Q')
        {
            for(int j = 1; j < 8; j += 2) {
                if(perm[j] != res) continue;
                if(mp.count(res)) continue;
                else
                {
                    cout << "YES"; return 0;
                }
            }
        }
        mp[res] = true;
    }
    cout << "NO";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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



