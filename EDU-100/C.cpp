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
    int n; cin >> n;
    vector<ll> t(n);
    map<ll, ll> x;
    map<ll, bool> pres;
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        pres[t[i]] = true;
        cin >> x[t[i]];
    }
    map<ll, ll> time;
    int in = 0;
    ll cur = 0;
    while(in < n) {
        time[t[in]] = cur;
        ll diff = abs(cur - x[t[in]]);
        time[t[in] + diff] = x[t[in]];
        cur = x[t[in]];
        if(diff != 0)
            in = lower_bound(all(t), t[in] + diff) - begin(t);
        else 
            in = upper_bound(all(t), t[in]) - begin(t);
    }
    debug(time);
    time[LLONG_MAX] = cur;
    vector<pair<ll, ll>> range;
    for(int i = 0; i < n; ++i) {
        ll tt = t[i];
        if(time.count(tt)) continue;
        else {
            auto it1 = time.lower_bound(tt); --it1;
            auto it2 = time.lower_bound(tt); 
            if((*it2).ss - (*it1).ss >= 0) {
                time[tt] = (tt - ((*it1).ff)) + ((*it1).ss);
            }
            else {
                time[tt] = ((*it1).ss) - (tt - ((*it1).ff));
            }
        }
    }
    int cnt = 0;
    for(auto val : time) range.push_back(val);
    for(int i = 0; i < sz(range) - 1; ++i) {
        if(!pres[range[i].ff]) continue;
        if(range[i].ss == x[range[i].ff]) ++cnt;
        else {
                ll a = range[i].ss;
                ll b = range[i + 1].ss;
                if(a < b) {
                    if(a <= x[range[i].ff] && x[range[i].ff] <= b) ++cnt;
                }
                else {
                    if(b <= x[range[i].ff] && x[range[i].ff] <= a) ++cnt;
                }
        }
    }
    cout << cnt;
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
