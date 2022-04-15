#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

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

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    std::vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    std::vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; i++) {
        int two = 0;
        while(v[i] % 2 == 0) v[i] /= 2, ++two;
        int five = 0;
        while(v[i] % 5 == 0) v[i] /= 5, ++five;
        ans[i] = {two, five};
    }
    sort(begin(ans), end(ans));
    // till i index, what is the maximum I can get if I can choose "j" numbers
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(k + 1, {0, 0}));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < k + 1; j++) {
            if(i == 0 || j == 0) continue;
            else
            {
                pi op1 = dp[i - 1][j];
                pi op2 = dp[i - 1][j - 1];
                int t = op2.first + ans[i - 1].first;
                int f = op2.second + ans[i - 1].second;
                op2 = {t, f};
                int min1 = min(op1.first, op1.second);
                int min2 = min(op2.first, op2.second);
                if(min1 > min2)
                {
                    dp[i][j] = op1;
                }
                else if(min2 > min1) dp[i][j] = op2;
                else
                {
                    int max1 = max(op1.first, op1.second);
                    int max2 = max(op2.first, op2.second);
                    if(max1 > max2) dp[i][j] = op1;
                    else dp[i][j] = op2;
                }
            }
        }
    }
    cout << min(dp[n][k].first, dp[n][k].second);
    return 0;
}
