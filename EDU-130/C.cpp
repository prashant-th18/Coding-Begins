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
    string a, b; cin >> a >> b;
    priority_queue<int> ca, cb, cc;
    for (int i = 0; i < n; i++) {
        if(a[i] == 'a') ca.push(i);
        else if(a[i] == 'b') cb.push(i);
        else cc.push(i);
    }
    int j = n - 1;
    vector<bool> vis(n, true);
    for(int i = n - 1; i >= 0; --i) {
        if(!vis[i]) continue;
        if(j < 0) {
            cout << "NO"; return 0;
        }
        char up = a[i], down = b[j];
        if(up == 'a') {
            if(down == 'a') {
                vis[ca.top()] = false;
                ca.pop(); --j;
            }
            else {
                cout << "NO"; return 0;
            }
        }
        else if(up == 'b') {
            if(down == 'c') {
                cout << "NO"; return 0;
            }
            else if(down == 'b') {
                vis[cb.top()] = false;
                cb.pop(); --j;
            }
            else {
                int ua = ((sz(ca) != 0) ? (ca.top()) : (-1));
                int uc = ((sz(cc) != 0) ? (cc.top()) : (-1));
                if(ua == -1) {
                    cout << "NO"; return 0;
                }
                else {
                    if(ua < uc) {
                        cout << "NO"; return 0;
                    }
                    else {
                        vis[ca.top()] = false;
                        --j;
                        ca.pop(); ++i;
                    }
                }
            }
        }
        else { // 'c'
            if(down == 'c') {
                vis[cc.top()] = false;
                cc.pop();
                --j;
            }
            else if(down == 'b') {
                int ub = ((sz(cb) != 0) ? (cb.top()) : (-1));
                int ua = ((sz(ca) != 0) ? (ca.top()) : (-1));
                if(ub == -1) {
                    cout << "NO"; return 0;
                }
                else {
                    if(ua > ub) {
                        cout << "NO"; return 0;
                    }
                    else {
                        vis[ub] = false;
                        --j;
                        cb.pop(); ++i;
                    }
                }
            }
            else {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES";
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
