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

int n;
vector<int> check;
vector<int> par;
void fun(int node) {
    cout << "? " << node << endl;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        v[temp[i]].push_back(i + 1);
    }
    for(const auto& val : v[1]) {
        if(par[val] == -1) {
            par[val] = node;
        }
        else if(par[val] != node) {
            par[node] = val;
        }
    }
    for(int i = 2; i < n; ++i) {
        if(sz(v[i - 1]) == 1) {
            for(const auto& val : v[i]) {
                if(par[val] == -1) par[val] = v[i - 1][0];
            }
        }
    }
}

// *-> KISS*
int solve() {
    cin >> n;
    if(n == 2) {
        cout << "!\n1 2" << endl;
        return 0;
    }
    par.assign(n + 1, -1);
    int root = -1, call = (n + 1) / 2;
    // Initial Call
    cout << "? 1" << endl;
    {
        vector<int> temp(n);
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            cin >> temp[i];
            if(temp[i] >= maxi) {
                maxi = temp[i];
                root = i + 1;
            }
        }
        --call;
    }
    par[root] = root;
    {
        // Assume tree to be rooted tree at root
        cout << "? " << root << endl;
        --call;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            cin >> temp[i];
        }
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; i++) {
            v[temp[i]].push_back(i + 1);
        }
        for(int i = 1; i < n; ++i) {
            if(sz(v[i - 1]) == 1) {
                for(const auto& val : v[i]) {
                    par[val] = v[i - 1][0];
                }
            }
            else {
                for(const auto& val : v[i]) check.push_back(val);
            }
        }
        debug(check);
        for (int i = 0; i < sz(check); i++) {
            if(par[check[i]] == -1) {
                fun(check[i]);
                --call;
            }
        }
    }
    assert(call >= 0);
    cout << "!" << endl;
    for(int i = 1; i <= n; ++i) {
        if(par[i] != i) {
            cout << i << ' ' << par[i] << endl;
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
