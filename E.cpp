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

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

vector<int> value, occ;
vector<vector<int>> v;
ordered_set st;
int ans = 0;
void check()
{
    int s = 0, e = sz(st) - 1;
    int aa = 0;
    while(s <= e)
    {
        int mid = (s + e) >> 1;
        if(*st.find_by_order(mid) == mid)
        {
            aa = mid + 1; s = mid + 1;
        }
        else e = mid - 1;
    }
    ans = max(ans, aa);
}
void dfs(int node, int par = -1)
{
    st.insert(value[node]);
    occ[value[node]]++;
    int c = 0;
    for(const auto& val : v[node])
    {
        if(val != par) ++c, dfs(val, node);
    }
    if(c == 0)
    {
        check();
    }
    --occ[value[node]];
    if(occ[value[node]] == 0) st.erase(st.find(value[node]));
}
// *-> KISS*
int solve() {
    st.clear();
    int n; cin >> n;
    value.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i + 1];
    }
    v.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    occ.assign(n + 1, 0);
    // Use ordered_set such that at every node first if it's not inserted till now, insert it
    // then at leaf, do binary search, and then while coming back, if occ[present element] > 1,
    // this means that we have found the same element above, so we will not erase present element from
    // ordered_set, otherwise, we will erase
    dfs(1);
    cout << ans;
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
