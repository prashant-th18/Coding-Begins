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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
    ll m; cin >> m;
    vector<vector<ll>> v(2, vector<ll>(m, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> lr(2, vector<ll>(m, LLONG_MAX));
    auto rl = lr;
    // lr -> left -> right
    // rl -> right -> left
    for(int i = m - 1; i >= 0; --i) {
        if(i == m - 1) {
            lr[0][i] = v[0][i] + 1;
            lr[1][i] = v[1][i] + 1;
        }
        else {
            lr[0][i] = max(lr[0][i + 1], v[0][i] + m - i);
            lr[1][i] = max(lr[1][i + 1], v[1][i] + m - i);
        }
        debug(lr[0][i], lr[1][i]);
    }
    for(int i = m - 1; i >= 0; --i) {
        if(i == m - 1) {
            rl[0][i] = v[0][i] + 1;
            rl[1][i] = v[1][i] + 1;
        }
        else {
            ll t1 = rl[0][i + 1] + 1;
            rl[0][i] = max(v[0][i] + 1, t1);
            ll t2 = rl[1][i + 1] + 1;
            rl[1][i] = max(v[1][i] + 1, t2);
        }
    }
    ll ans = LLONG_MAX;
    ans = max(rl[1][0], lr[0][1] + m);
    debug(ans);
    ll ti = v[1][0] + 1, i = 1;
    for(int j = 0; j < m - 1; ++j) {
        if(i == 1) {
            ll temp = max(lr[1][j + 1], ti + m - j - 1);
            temp = max(rl[0][j + 1], temp + m - j - 1);
            ans = min(ans, temp);
            if(j + 1 <= m - 1) {
                ti = max(ti, v[1][j + 1]) + 1;
                ti = max(ti, v[0][j + 1]) + 1;
            }
            i = 0;
        }
        else {
            ll temp = max(ti + m - 1 - j, lr[0][j + 1]);
            temp = max(rl[1][j + 1], temp + m - 1 - j);
            ans = min(ans, temp);
            if(j + 1 <= m - 1) {
                ti = max(ti, v[0][j + 1]) + 1;
                ti = max(ti, v[1][j + 1]) + 1;
            }
            i = 1;
        }
        debug(ans);
    }
    ans = min(ans, ti);
    cout << ans;
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
