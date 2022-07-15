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

int N = 1e5 + 1;
vector<int> spf(N, -1);
void init() {
    for(ll i = 2; i < N; ++i) {
        if(spf[i] == -1) {
            spf[i] = i;
            for(ll j = i * i; j < N; j += i) spf[j] = i;
        }
    }
}
// *-> KISS*
int solve() {
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(k == 2) {
        map<int, int> cnt;
        for(int i = 0; i < n; ++i) {
            ll mul = 1;
            while(spf[v[i]] != -1) {
                int t = spf[v[i]], c = 0;
                while(v[i] % t == 0) v[i] /= t, ++c;
                if(c & 1) {
                    mul *= t;
                }
            }
            v[i] = mul;
            cnt[mul]++;
        }
        debug(v);
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (cnt[v[i]] - 1);
            cnt[v[i]]--;
        }
        cout << ans;
    }
    else {
        ll ans = 0;
        map<int, ll> cnt;
        for (int i = 0; i < n; i++) {
            cnt[v[i]]++;
        }
        auto check = [&](ll& i) {
            ll res = i;
            int c = 1;
            while(c < k && i <= (ll)1e10 / res) {
                ++c;
                res *= i;
            }
            if(c == k) {
                return res;
            }
            else return -1LL;
        };
        for(ll i = 1;; ++i) {
            ll temp = check(i);
            if(temp == -1) break;
            for(ll j = 1; j * j <= temp; ++j) {
                if(temp % j == 0) {
                    ll f = j, s = temp / j;
                    if(f != s) {
                        ans += cnt[f] * cnt[s];
                    }
                    else {
                        ans += ((cnt[f]) * (cnt[f] - 1)) / 2;
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
    init();
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

