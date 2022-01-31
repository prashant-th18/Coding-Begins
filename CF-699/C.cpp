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
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &val : a) {
        cin >> val;
    }
    vector<int> b(n);
    for (int &val : b) {
        cin >> val;
    }
    vector<int> c(m), occ(n + 1, 0);
    for (int &val : c) {
        cin >> val;
        occ[val]++;
    }
    vector<int> need(n + 1, 0);
    vector<bool> present(n + 1, false);
    vector<deque<int>> ne(n + 1), extra(n + 1);
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i])
        {
            need[b[i]]++;
            ne[b[i]].push_back(i + 1);
        }
        else
        {
            extra[b[i]].push_back(i + 1);
        }
        present[b[i]] = true;
    }
    for(int i = 0; i <= n; ++i)
    {
        if(occ[i] < need[i])
        {
            cout << "NO"; return 0;
        }
    }
    vector<int> ans(m);
    for(int i = m - 1; i >= 0; --i)
    {
        if(need[c[i]] == 0 && !present[c[i]])
        {
            if(i == m - 1)
            {
                cout << "NO"; return 0;
            }
            else
            {
                ans[i] = ans[m - 1];
            }
        }
        else if(need[c[i]] == 0)
        {
            ans[i] = extra[c[i]].front();
        }
        else
        {
            ans[i] = ne[c[i]].front();
            if(sz(ne[c[i]]) != 1) ne[c[i]].pop_front();
        }
    }
    cout << "YES\n";
    for(auto val : ans) cout << val << ' ';
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
