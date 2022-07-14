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

// *-> KISS*
int solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    multiset<int> sst;
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        sst.insert(t);
        ++mp[t];
    }
    {
        int num = *sst.begin();
        for(int i = 0; i < m; ++i) {
            assert(sz(sst) > 0);
            auto it = sst.lower_bound(num);
            if(it == sst.end()) it = sst.begin();
            v.push_back(*it);
            num = *it + 1;
            sst.erase(it);
        }
    }
    vector<vector<int>> days(100 * m);
    set<pair<int, int>> st;
    for(int i = 1; i <= n; ++i) st.insert(pair(mp[i], i));
    int d = 0; //////////////////
    auto fun = [&]() -> void {
        if(sz(days[d]) == 0) ++d;
        if(sz(days[d]) == 0) ++d;
        while(sz(days[d])) {
            st.insert(pair(mp[days[d].back()], days[d].back()));
            days[d].pop_back();
        }
    };
    debug(v);
    for (int i = 0; i < sz(v); i++) {
        int num = v[i];
        if(sz(st) == 0) fun();
        if(st.count(pair(mp[num], num))) {
            st.erase(pair(mp[num], num));
            days[d + 1].push_back(num);
            --mp[num];
        }
        else {
            auto p = *st.begin();
            days[d + 2].push_back(p.ss);
            st.erase(p);
            --mp[num];
        }
    }
    debug(d);
    int ind = 0;
    for(int i = 1; i <= 10; ++i) if(sz(days[i + d])) ind = i;
    cout << d + ind;
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
