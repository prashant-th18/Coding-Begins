/*
 * neg - pos = 3 * k
 * => k = (neg - pos) / 3
 */
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> dp(n + 1, 0);
        auto neg = dp, pos = dp;
        for(int i = 0; i < n; ++i)
        {
            neg[i + 1] = neg[i] + (s[i] == '-');
            pos[i + 1] = pos[i] + (s[i] == '+');
            if(i != 0)
            {
                dp[i + 1] = max(dp[i], (s[i - 1] == s[i] && s[i] == '-') + dp[i - 1]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; ++j)
            {
                int nn = neg[j + 1] - neg[i];
                int pp = pos[j + 1] - pos[i];
                if(nn >= pp && (nn - pp) % 3 == 0)
                {
                    int k = (nn - pp) / 3;
                    if(dp[j + 1] - dp[i + 1] >= k)
                    {
                        ++cnt;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
