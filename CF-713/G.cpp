#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 1;

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

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr);
    vector<int> spf(N, -1);
    for(int i = 2; i < N / i; ++i)
    {
        if(spf[i] == -1)
        {
            for(int j = i * i; j < N; j += i)
            {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
    int test; cin >> test;
    vector<int> sum(N, -1);
    sum[1] = 1;
    for (int i = 2; i < N; i++) {
        ll num = 1;
        ll den = 1;
        ll temp = i;
        while(spf[temp] != -1)
        {
            ll ss = spf[temp];
            ll res = ss;
            while(temp % ss == 0) temp /= ss, res *= ss;
            --res;
            num *= res;
            den *= (ss - 1);
        }
        if(temp != 1)
        {
            num *= (temp * temp - 1);
            den *= (temp - 1);
        }
        num /= den;
        if(num < N && sum[num] == -1) sum[num] = i;
    }
    //debug(sum);
    while(test--)
    {
        int c; cin >> c;
        cout << sum[c] << '\n';
    }
    return 0;
}
