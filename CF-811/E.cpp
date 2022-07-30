#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto orig = v;
    vector<vector<ll>> order(n);
    for (int i = 0; i < n; i++) {
        set<int> st;
        for(int j = 0; j < 3; ++j) {
            while(st.count(v[i] % 10) == false) {
                st.insert(v[i] % 10);
                order[i].push_back(v[i] % 10);
                v[i] += (v[i] % 10);
            }
            st.clear();
        }
    }
    v = orig;
    {
        for (int i = 0; i < n; i++) {
            reverse(all(order[i]));
            order[i].push_back(0);
            reverse(all(order[i]));
        }
        vector<vector<ll>> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = vector<ll>(sz(order[i]), 0);
            for(int j = 0; j < sz(order[i]); ++j) {
                if(j == 0) {
                    pre[i][j] = order[i][j];
                }
                else {
                    pre[i][j] = pre[i][j - 1] + order[i][j];
                }
            }
        }
        ll maxx = *max_element(all(
        for (int i = 0; i < sz(order[0]); i++) {
            ll num = v[0] + pre[0][i];
            bool f = true;
            for(int j = 1; j < n && f; ++j) {
                // v[i] -> num
                int s = 0, e = sz(pre[j]) - 1;
                bool op = false;
                while(s <= e) {
                    int mid = midpoint(s, e);
                    ll su = v[j] + pre[j][mid];
                    if(su == num) {
                        op = true; break;
                    }
                    else if(su < num) s = mid + 1;
                    else e = mid - 1;
                }
                if(!op) f = false;
            }
            if(f) {
                cout << "Yes"; return 0;
            }
        }
    }
    cout << "No";
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

        if (solve()) {
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
