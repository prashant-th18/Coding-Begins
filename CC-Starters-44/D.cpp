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
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> occ;
    int maxx = 0;
    for(auto val : s) occ[val]++, maxx = max(maxx, occ[val]);
    map<int, deque<char>, greater<int>> mp;
    for(auto val : occ) {
        mp[val.ss].push_back(val.ff);
    }
    string res = string(n, '.');
    int j = 0;
    vector<int> recent(26, -1);
    auto check = [&](int i, char ch) {
        int ind = ch - 'a';
        if(recent[ind] == -1 || i - recent[ind] >= 3) {
            recent[ind] = i;
            return true;
        }
        return false;
    };
    while(sz(mp) != 0) {
        bool flag = false;
        for(auto it = mp.begin(); it != mp.end() && !flag;) {
            auto& dq = (*it).second;
            char ch = dq.front();
            if(check(j, ch)) {
                res[j++] = ch;
                if((*it).first == 1) dq.pop_front();
                else {
                    mp[(*it).first - 1].push_back(ch);
                    dq.pop_front();
                }
                flag = true;
                if(sz(dq) == 0) it = mp.erase(it);
            }
            else ++it;
        }
        if(flag == false) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << res;
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
