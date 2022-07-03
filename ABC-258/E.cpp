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
    ll n, q, tot = 0; cin >> n >> q;
    ll x; cin >> x;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        tot += w[i];
    }
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + w[i];
    }
    ll atLeast = x / tot;
    int in = 0;
    vector<int> vis(n, -1);
    auto find = [&](int ind, ll rem) -> int {
        int s = ind, e = n - 1;
        int ans = ind;
        while(s <= e) {
            ll mid = (s + e) / 2;
            if(pre[mid + 1] - pre[ind] >= rem) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    };
    int last = 0, c = 0;
    vector<ll> ans;
    while(vis[in] == -1) {
        vis[in] = c++;
        ll rem = x - atLeast * tot;
        ll temp = atLeast * n;
        if(rem == 0) {
            ans.push_back(temp);
            break;
        }
        else {
            ll tt = pre[n] - pre[in];
            int where = 0;
            if(tt >= rem) {
                where = find(in, rem);
                temp += (where - in + 1);
                in = (where + 1) % n;
            }
            else {
                temp += (n - in);
                rem -= (tt);
                where = find(0, rem);
                temp += (where + 1);
                in = (where + 1) % n;
            }
            ans.push_back(temp);
            last = vis[in];
        }
    }
    debug(ans);
    while(q--) {
        ll k; cin >> k;
        --k;
        if(k >= sz(ans)) {
            k -= sz(ans);
            k = k % (sz(ans) - last);
            cout << ans[last + k] << '\n';
        }
        else {
            cout << ans[k] << '\n';
        }
    }
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
