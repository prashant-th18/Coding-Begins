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

// *-> KISS*
int solve() {
    int n;
    string s; cin >> s;
    string p = s; // Reversed s
    reverse(all(p));
    n = sz(s);
    vector<char> order;
    map<char, bool> pres;
    for(int i = 0; i < sz(p); ++i) {
        if(pres.count(p[i]) == false) {
            pres[p[i]] = true;
            order.push_back(p[i]);
        }
    }
    {
        if(sz(order) == 1) {
            cout << s << ' ' << order[0]; return 0;
        }
    }
    // Reverse order to correct
    reverse(all(order));
    vector<vector<int>> v(26); // Lowercase Letters positions
    for(int i = 0; i < sz(p); ++i) {
        v[p[i] - 'a'].push_back(i);
    }
    map<char, int> real; // Real occurrence
    for(int i = 0; i < sz(order); ++i) {
        if(sz(v[order[i] - 'a']) % (i + 1) != 0) {
            cout << -1; return 0;
        }
        real[order[i]] = sz(v[order[i] - 'a']) / (i + 1);
    }
    // Again reverse order for below code
    reverse(all(order));
    int ans = 0;
    // Remember 0 based
    for(int i = sz(order) - 2; i < sz(order) - 1; ++i) {
        map<char, int> ps; // Pseudo
        for(int j = 0; j <= i; ++j) {
            ps[order[j]] = real[order[j]] * (i - j + 1);
        }
        for(auto& val : ps) {
            ans = max(ans, v[val.ff - 'a'][val.ss - 1]);
        }
    }
    ans = n - 2 - ans;
    // Again reverse order
    reverse(all(order));
    string res = s.substr(0, ans + 1);
    auto check = [&](int& in, string& rs) -> bool {
        if(in + sz(rs) > sz(s)) return false;
        for (int i = 0; i < sz(rs); i++) {
            if(s[in] == rs[i]) ++in;
            else return false;
        }
        return true;
    };
    auto remove = [&](int& c, string& re) -> string {
        string r = "";
        for (int i = 0; i < sz(re); i++) {
            if(re[i] != order[c]) r += re[i];
        }
        ++c;
        return r;
    };
    {
        int i = 0, c = 0;
        while(res != "") {
            if(!check(i, res)) {
                cout << -1; return 0;
            }
            res = remove(c, res);
        }
        cout << s.substr(0, ans + 1) << ' ';
        for(auto val : order) cout << val;
    }
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
