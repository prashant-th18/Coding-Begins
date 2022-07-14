#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
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
    ll n, k; cin >> n >> k;
    /* vector<int> v(n, 0);
    iota(all(v), 1);
    do {
        bool flag = true;
        for(int i = 0; i < n - 1 && flag; ++i) {
            if(v[i + 1] < v[i] - 1) {
                flag = false;
            }
        }
        if(flag) {
            debug(v);
        }
    } while (next_permutation(all(v))); */
    ordered_set st;
    for(int i = 1; i <= n; ++i) st.insert(i);
    if(n < 61) {
        if((1LL << (n - 1)) < k) {
            cout << -1; return 0;
        }
    }
    vector<ll> v;
    while(k && sz(st)) {
        if(n >= 62) {
            v.push_back(*(st.begin()));
            st.erase(st.begin());
        }
        else {
            ll sum = 0, in = 0, cnt = max(0LL, n - 2);
            for(auto val : st) {
                if(sum + (1LL << cnt) >= k) {
                    if(sum + (1LL << cnt) == k) sum += (1LL << cnt);
                    break;
                }
                sum += (1LL << cnt);
                cnt = max(0LL, cnt - 1);
                ++in;
            }
            k -= sum;
            auto it = (st.find_by_order(in));
            v.push_back(*it);
            st.erase(it);
            --in;
            while(k == 0 && in >= 0) {
                v.push_back(*st.find_by_order(in));
                st.erase(st.find_by_order(in));
                --in;
            }
        }
        --n;
    }
    while(sz(st)) {
        v.push_back(*st.rbegin());
        st.erase(st.rbegin());
    }
    for(auto val : v) cout << val << ' ';
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
