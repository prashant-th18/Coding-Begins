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

int k;
vector<int> bad(26);
struct node {
    bool eow = true;
    
    node* a[26] = {nullptr};
};
int insert(node* root, string s) {
    node* temp = root;
    int count = 0, lim = 0;
    for (int i = 0; i < sz(s); i++) {
        int ind = s[i] - 'a';
        if(lim + bad[ind] > k) {
            break;
        }
        lim += bad[ind];
        if(temp -> a[ind] == nullptr) temp -> a[ind] = new node;

        temp = temp -> a[ind];
        if(temp -> eow) ++count;
        temp -> eow = false;
    }
    return count;
}
// *-> KISS*
int solve() {
    string s; cin >> s;
    for (int i = 0; i < 26; i++) {
        char ch; cin >> ch;
        bad[i] = 1 - (ch - '0');
    }
    cin >> k;
    node* root = new node;
    int ans = 0;
    for(int i = 0; i < sz(s); ++i) {
        ans += insert(root, s.substr(i));
    }
    cout << ans;
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
