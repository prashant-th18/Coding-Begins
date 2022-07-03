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

// *-> KISS*
int solve() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    vector<deque<ll>> v(3);
    for (int i = 0; i < 3; i++) {
        deque<ll> t;
        int ss = 0;
        if(i == 0) ss = n1;
        else if(i == 1) ss = n2;
        else ss = n3;
        for(int j = 0; j < ss; ++j) {
            ll tt; cin >> tt;
            t.push_back(tt);
        }
        sort(t.begin(), t.end(), greater<ll>());
        v[i] = (t);
    }
    ll maxx = LLONG_MIN;
    vector<int> perm = {0, 1, 2};
    do {
        auto a = v[perm[0]], b = v[perm[1]], c = v[perm[2]];
        a[0] += (b.front() - c.back());
        b.pop_front();
        c.pop_back();
        while(sz(b) != 0 && sz(c) != 0) {
            bool flag = true;
            if(c.front() - b.back() > b.front() - c.back()) flag = false;
            if(flag) {
                a[0] += b.front() - c.back();
                b.pop_front(); c.pop_back();
            }
            else {
                a[0] += c.front() - b.back();
                c.pop_front(); b.pop_back();
            }
        }
        ll s1 = accumulate(all(a), 0LL), s2 = accumulate(all(b), 0LL), s3 = accumulate(all(c), 0LL);
        maxx = max(maxx, s1 - s2 - s3);
    } while (next_permutation(all(perm)));
    cout << maxx;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
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
