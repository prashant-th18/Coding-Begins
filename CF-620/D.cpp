#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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

deque<int> maxLength(int n, string p) {
    deque<int> t(n, 0), dq(n, 0);
    iota(all(dq), 1);
    for(int i = 0; i < n - 1; ++i) {
        if(p[i] == '<') {
            t[i] = dq.front(); dq.pop_front();
        }
        else {
            int j = i, c = 0;
            while(j < n - 1 && p[j] == '>') ++j;
            c = j;
            while(j >= i) {
                t[j--] = dq.front(); dq.pop_front();
            }
            i = c;
        }
    }
    if(sz(dq)) t[n - 1] = dq.front();
    return t;
}
deque<int> minLength(int n, string p) {
    deque<int> t(n, 0), dq(n, 0);
    iota(all(dq), 1);
    reverse(all(dq));
    for(int i = 0; i < n - 1; ++i) {
        if(p[i] == '>') {
            t[i] = dq.front(); dq.pop_front();
        }
        else {
            int j = i, c = 0;
            while(j < n - 1 && p[j] == '<') ++j;
            c = j;
            while(j >= i) {
                t[j--] = dq.front(); dq.pop_front();
            }
            i = c;
        }
    }
    if(sz(dq)) t[n - 1] = dq.front();
    return t;
}
void print(deque<int> t) {
    for(auto val : t) cout << val << ' ';
    cout << '\n';
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string s; cin >> s;
    print(minLength(n, s));
    print(maxLength(n, s));
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    if(test) cin >> TET;
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
