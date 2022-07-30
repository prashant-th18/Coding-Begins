#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef unsigned long long ll;
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
    ll l, r; cin >> l >> r;
    vector<vector<ll>> v(100, vector<ll>(4, 0));
    v[1][0] = v[1][1] = v[1][2] = v[1][3] = 1;
    v[2][0] = 2; v[2][1] = 4; v[2][2] = 2; v[2][3] = 3;
    for(int i = 3;; ++i) {
        vector<ll>& t = v[i - 2];
        v[i][0] = t[1] + 2;
        v[i][1] = v[i][0] + (1LL << (i)) - 2;
        v[i][2] = v[i - 1][3] + 1;
        v[i][3] = (1LL << (i - 1)) + v[i][2] - 1;
        if(v[i][3] > (ll)1e18) break;
    }
    auto add = [&](ll a, ll b) {
        a %= MOD;
        b %= MOD;
        return (a + b) % MOD;
    };
    auto mul = [&](ll a, ll b) {
        return (a % MOD * b % MOD) % MOD;
    };
    auto sub = [&](ll a, ll b) {
        return (a % MOD + MOD - b % MOD) % MOD;
    };
    auto searchSum = [&](ll num) -> ll {
        ll sum = 0, even = 0, odd = 0;
        for(int i = 1;; i++) {
            ll last = v[i][1];
            if(v[i][2] <= num && num <= v[i][3]) {
                debug(num - v[i][2]);
                if(last & 1) {
                    ll rem = num - v[i][2];
                    ll in = v[i][0] + 2 * rem;
                    in = (in + 1) >> 1;
                    odd = mul(in, in);
                    sum = add(odd, even);
                }
                else {
                    ll rem = num - v[i][2];
                    ll in = v[i][0] + 2 * rem;
                    in >>= 1;
                    even = mul(in, in + 1);
                    sum = add(odd, even);
                }
                break;
            }
            else {
                if(last & 1) {
                    ll in = (last + 1) >> 1;
                    odd = mul(in, in);
                }
                else {
                    ll in = (last) >> 1;
                    even = mul(in, in + 1);
                }
            }
        }
        return sum;
    };
    cout << sub(searchSum(r), max(0ULL, searchSum(l - 1)));
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
