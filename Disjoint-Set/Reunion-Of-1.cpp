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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> par(n, 0), rank(n, 0);
    multiset<int, greater<int>> st;
    st.insert(0);
    for (int i = 0; i < n; i++) {
        if(s[i] == '1') {
            par[i] = -1;
            rank[i] = 1;
            st.insert(1);
        }
    }
    auto find = [&](int a) -> int {
        vector<int> temp;
        while(par[a] > 0) {
            temp.push_back(a);
            a = par[a];
        }
        for(auto val : temp) par[val] = a;
        return a;
    };
    
    auto un = [&](int a, int b) -> void {
        a = find(a);
        b = find(b);
        if(a == b) return;
        st.erase(st.find(rank[b]));
        st.erase(st.find(rank[a]));    
        st.insert(rank[a] + rank[b]);
        if(rank[a] > rank[b]) {
            rank[a] += rank[b];
            par[b] = a;
        }
        else {
            rank[b] += rank[a];
            par[a] = b;
        }
    };
    for (int i = 0; i < n - 1; i++) {
        if(s[i] == '1' && s[i + 1] == '1') {
            un(i, i + 1);
        }
    }
    while(k--) {
        int t; cin >> t;
        if(t == 1) {
            cout << (*st.begin()) << '\n';
        }
        else {
            int i; cin >> i;
            --i;
            if(s[i] == '0') {
                s[i] = '1';
                par[i] = -1, rank[i] = 1;
                st.insert(1);
                if(i - 1 >= 0 && s[i - 1] == '1') un(i - 1, i);
                if(i + 1 < n && s[i + 1] == '1') un(i, i + 1);
            }
        }
    }
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
