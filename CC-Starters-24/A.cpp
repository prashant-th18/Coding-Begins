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
    int n; cin >> n;
    string s; cin >> s;
    priority_queue<pair<int, char>> pq;
    vector<int> occ(26);
    for (int i = 0; i < n; i++) {
        occ[s[i] - 97]++;
    }
    for(char ch = 'a'; ch <= 'z'; ++ch)
    {
        if(occ[ch - 97] == 0) continue;
        pq.push(pair(occ[ch - 97], ch));
    }
    string res = string(n, '.');
    int i = 0, j = n - 1;
    while(sz(pq) != 0)
    {
        if(sz(pq) == 1)
        {
            auto p = pq.top(); pq.pop();
            res[i++] = p.second;
            p.first--;
            if(p.first) pq.push(p);
        }
        else
        {
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            res[i++] = p1.second;
            res[j--] = p2.second;
            p1.first--;
            p2.first--;
            if(p1.first) pq.push(p1);
            if(p2.first) pq.push(p2);
        }
    }
    auto fun = [&](string tt) -> bool
    {
        for(int ii = 0; ii < sz(tt); ++ii)
        {
            if(tt[ii] == tt[sz(tt) - 1 - ii]) return false;
        }
        return true;
    };
    if(!fun(res))
    {
        cout << "No";
    }
    else
    {
        cout << "Yes\n";
        cout << res;
    }
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
}
// -> Keep It Simple Stupid!
