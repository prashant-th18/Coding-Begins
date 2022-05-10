#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, x, y; cin >> n >> m >> x >> y;
    --x; --y;
    vector<array<ll, 2>> dp(m + 1, {0, 0});
    vector<vector<char>> v(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int h = 0, d = 0;
        for(int j = 0; j < n; ++j) {
            h += (v[j][i] == '#');
            d += (v[j][i] == '.');
        }
        dp[i + 1][0] = dp[i][0] + h;
        dp[i + 1][1] = dp[i][1] + d;
    }
    vector<array<ll, 2>> ans(m, {INT_MAX, INT_MAX});
    for(int i = 0; i < m; ++i) {
        int j = i;
        // # bnalo
        // . bnalo
        int dot = 0;
        while(j < m && j - i <= y) {
            dot = (dp[j + 1][1] - dp[i][1]);
            if(j - i >= x) {
                ll op = (i == 0) ? (0) : (ans[i - 1][1]);
                ans[j][0] = min(op + dot, ans[j][0]);
            }
            ++j;
        }
        j = i;
        int hash = 0;
        while(j < m && j - i <= y) {
            hash = (dp[j + 1][0] - dp[i][0]);
            if(j - i >= x) {
                ll op = (i == 0) ? (0) : (ans[i - 1][0]);
                ans[j][1] = min(ans[j][1], op + hash);
            }
            ++j;
        }
    }
    debug(ans);
    cout << min(ans[m - 1][0], ans[m - 1][1]);
    return 0;
}
