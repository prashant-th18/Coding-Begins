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

// *-> KISS*
int solve() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    if((n1 & 1) && (n2 & 1) && (n3 & 1)) cout << "NO";
    else if(n1 % 2 == 0 && n2 % 2 == 0 && n3 % 2 == 0) {
        cout << "NO";
    }
    else {
        int odd = (n1 & 1) + (n2 & 1) + (n3 & 1);
        if(odd == 1) {
            if(n1 & 1) ++n1;
            else if(n2 & 1) ++n2;
            else ++n3;
        }
        else {
            if(n1 % 2 == 0) ++n1;
            else if(n2 % 2 == 0) ++n2;
            else ++n3;
        }
        vector<vector<int>> v(3, vector<int>(128, 0));
        for(int i = 0; i < 32; ++i) {
            v[0][i] = ((n1 >> i) & 1);
        }
        for (int i = 0; i < 32; i++) {
            v[1][i] = ((n2 >> i) & 1);
        }
        for (int i = 0; i < 32; i++) {
            v[2][i] = ((n3 >> i) & 1);
        }
        //debug(v[0]); debug(v[1]); debug(v[2]);
        for(int i = 1; i < 128; ++i) {
            vector<int> temp;
            for(int j = 0; j < 3; ++j) {
                if(v[j][i] != 0) temp.push_back(j);
            }
            if(sz(temp) == 1) {
                int in = temp[0];
                bool f = false;
                for(int j = i; j < 128 && (!f); ++j) {
                    v[in][j] = (v[in][j] + 1) % 2;
                    if(v[in][j] == 1) f = true;
                }
                if(!f) {
                    cout << "NO"; return 0;
                }
            }
            else if(sz(temp) == 2) {
                int in = 2;
                for(int j = 0; j < 2 && in == 2; ++j) {
                    if(temp[j] != j) in = j;
                }
                v[in][i] = 1;
            }
            else {
                bool f = true;
                for(int j = i; j < 128 && f; ++j) {
                    if(v[0][j] == v[1][j] && v[1][j] == v[2][j]) {} 
                    else f = false;
                }
                if(f) {
                    cout << "YES";
                }
                else cout << "NO";
                return 0;
            }
        }
        cout << "YES";
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
    return 0;
}
// -> Keep It Simple Stupid!
