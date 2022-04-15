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

#ifdef LOCAL
    void debug_print(string s) {
        cerr << "\"" << s << "\"";
    }

    void debug_print(const char* s) {
        debug_print((string)s);
    }

    void debug_print(bool val) {
        cerr << (val ? "true" : "false");
    }

    void debug_print(int val) {
        cerr << val;
    }

    void debug_print(ll val) {
        cerr << val;
    }

    void debug_print(double val) {
        cerr << val;
    }

    template<typename F, typename S>
    void debug_print(pair<F, S> val) {
        cerr << "(";
        debug_print(val.first);
        cerr << ", ";
        debug_print(val.second);
        cerr << ")";
    }

    void debug_print(vector<bool> val) {
        cerr << "{";
        bool first = true;
        for (bool x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    template<typename T>
    void debug_print(T val) {
        cerr << "{";
        bool first = true;
        for (const auto &x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    void debug_print_collection() {
        cerr << endl;
    }

    template<typename First, typename... Args>
    void debug_print_collection(First val, Args... args) {
        cerr << " ";
        debug_print(val);
        debug_print_collection(args...);
    }

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
    #define debug(...) 
#endif

int cc = 0;
void fun(vector<int>& ans)
{
    if(ans.empty()) return;
    int last = 0;
    for(int i = 0; i < sz(ans); ++i)
    {
        if(ans[i] == ans[0]) last = i;
        else break;
    }
    --ans[last];
    for(int i = 0; i < sz(ans); ++i) --ans[i];
    ++cc;
    while(sz(ans) != 0 && ans.back() <= 0) ans.pop_back();
    fun(ans);
}
// *-> KISS*
int solve() {
    cc = 0;
    int n; cin >> n;
    vector<int> par(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int tt; cin >> tt;
        par[tt]++;
    }
    vector<int> ans;
    for(int i = 0; i <= n; ++i) if(par[i] != 0) ans.push_back(par[i]);
    ans.push_back(1);
    sort(all(ans));
    reverse(all(ans));
    cc += sz(ans);
    for(int i = 0; i < sz(ans); ++i)
    {
        ans[i] -= (sz(ans) - i);
    }
    vector<int> temp = ans;
    ans.clear();
    while(sz(temp) != 0)
    {
        if(temp.back() > 0) ans.push_back(temp.back());
        temp.pop_back();
    }
    sort(ans.rbegin(), ans.rend());
    debug(ans, cc);
    fun(ans);
    cout << cc;
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
