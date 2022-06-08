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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int> st;
    int s = 0;
    for(int i = 1; i < n; ++i) {
        if(i == n - 1) {
            if(v[i] < v[i - 1] ) {
                st.insert(s);
                st.insert(n - 1);
            }
            else st.insert(s);
        }
        else if(v[i] < v[i - 1]) {
            st.insert(s);
            s = i;
        }
    }
    debug(st);
    while(m--) {
        int k, d; cin >> k >> d;
        --k;
        if(k == 0) {
            if(n >= 2) {
                if(v[k] >= v[k + 1]) {
                    v[k] -= d;
                    if(v[k] <= v[k + 1]) {
                        st.erase(k + 1);
                        st.insert(k);
                    }
                }
                else {
                    v[k] -= d;
                }
            }
            else 
            v[k] -= d;
        }
        else if(k == n - 1) { 
            if(v[k] < v[k - 1]) {
                v[k] -= d;
            }
            else {
                v[k] -= d;
                if(v[k] < v[k - 1]) st.insert(k);
            }
        }
        else {
            // Deal with ahead first
            if(v[k] < v[k + 1]) {
                if(v[k] < v[k - 1]) {
                    v[k] -= d;
                }
                else {
                    v[k] -= d;
                    // Increasing
                    if(v[k] >= v[k - 1]) {}
                    else {
                        st.insert(k);
                    }
                }
            }
            else {
                if(v[k] < v[k - 1]) {
                    
                }
            }
        }
        else {
            if(v[k] < v[k - 1]) {
                if(k + 1 < n) {
                    if(v[k] >= v[k + 1]) {
                        v[k] -= d;
                        if(v[k] <= v[k + 1]) st.insert(k), st.erase(k + 1);
                    }
                    else v[k] -= d;
                }
                else {
                    v[k] -= d;
                }
            }
            else { // >=
                // Was train behind
                if(k + 1 < n) {
                    if(v[k] > v[k + 1]) {
                        v[k] -= d;
                        if(v[k] <= v[k + 1]) {
                            st.insert(k); st.erase(k + 1);
                            if(v[k] < v[k - 1]) {
                                st.insert(k);
                            }
                            else {}
                        }
                        else {
                            if(v[k] < v[k - 1]) {
                                st.insert(k);
                            }
                        }
                    }
                    else {
                        v[k] -= d;
                        if(v[k] < v[k - 1]) st.insert(k);
                    }
                }
                else {
                    v[k] -= d;
                    if(v[k] < v[k - 1]) st.insert(k);
                }
            }
        }
        cout << sz(st) << ' ';
        debug(st);
        debug(v);
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
