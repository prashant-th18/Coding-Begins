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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) { 
        cin >> v[i]; 
    }
    vector<int> help;
    map<int, int> mp;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n / 2; i++) {
        mp[v[i] + v[n - 1 - i]]++;
        vec.push_back({v[i], v[n - 1 - i]});
        help.push_back(min(v[i], v[n - 1 - i]));
    }
    sort(help.begin(), help.end());
    sort(vec.begin(), vec.end(), [&](pair<int, int> a, pair<int, int> b) {
        return a.ff + a.ss < b.ff + b.ss;
    });
    int mini = INT_MAX;
    for(int i = 2; i <= 2 * k; ++i)
    {
        int uindex = lower_bound(all(help), i) - begin(help);
        if(i >= k + 2)
        {
            int cc = 0;
            cc += (uindex) + (sz(help) - uindex) * 2;
            // [1, i - k]
            int s = 0, e = sz(vec) - 1;
            int ans = -1;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                int temp = max(vec[mid].ff, vec[mid].ss);
                temp += k;
                if(temp < i)
                {
                    ans = mid + 1;
                    s = mid + 1;
                }
                else e = mid - 1;
            }
            if(ans != -1)
                cc += ans;
            cc -= mp[i];
            mini = min(mini, cc);
        }
        else
        {
            int cc = 0;
            cc += (sz(help) - uindex) * 2 + uindex;
            cc -= mp[i];
            mini = min(mini, cc);
        }
    }
    cout << mini;
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
