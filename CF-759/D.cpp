#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
using pii = pair<int, int>;

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    vector<set<int>> occ(n + 1);
    ordered_set st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(pair(i, v[i]));
        occ[v[i]].insert(i);
    }
    bool check = false;
    int rec = -1;
    for(int i = 1; i <= n; ++i) {
        while(sz(occ[i])) {
            int ind = *(occ[i].begin()); occ[i].erase(occ[i].begin());
            auto p = pair(ind, i);
            // Number of elements less than p
            int less = st.order_of_key(p);
            check |= (i == rec);
            st.erase(p);
            if(less % 2 == 1) {
                if(sz(st) == 1) {
                    if((*st.begin()).ss == i || check) {
                        cout << "YES"; 
                    }
                    else {
                        cout << "NO";
                    }
                    return 0;
                }
                else {
                    auto it1 = *st.begin(); st.erase(st.begin());
                    auto it2 = *st.begin(); st.erase(st.begin());
                    int i1, v1, i2, v2;
                    i1 = it1.ff, v1 = it1.ss;
                    i2 = it2.ff, v2 = it2.ss;
                    occ[v1].erase(i1);
                    occ[v2].erase(i2);
                    if(v1 == v2) {
                        check = true;
                        rec = v1;
                        continue;
                    }
                    occ[v2].insert(i1);
                    occ[v1].insert(i2);
                    st.insert(pair(i2, v1));
                    st.insert(pair(i1, v2));
                }
            }
            rec = i;
        }
    }
    cout << "YES";
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
