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
const long long MOD = 1000000007;
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

int n, N = 1e6;
vector<int> v, t, ans;
vector<int> fact(N, 1);
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t[in] = ans[s];
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
int query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) {
        return 0;
    }
    else if(s == qs && e == qe) return t[in];
    else {
        int mid = (s + e) / 2;
        return query(2 * in, s, mid, qs, min(qe, mid)) + query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe);
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
template<typename T>
T binexp(T a, T b) {
    T anss = 1;
    while (b) {
        if (b & 1) {
            anss = 1LL * anss * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return anss;
}
ll inv(ll a) {
    return binexp(a, MOD - 2);
}
ll ncr(ll nn, ll r) {
    if(r > nn) return 0;
    return fact[nn] * inv(fact[nn - r]) % MOD * inv(fact[r]) % MOD;
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    ans.assign(n, 1);
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]] = i;
    }
    int i = mp[0] - 1, j = mp[0] + 1;
    vector<pair<int, int>> loc;
    loc.push_back(pair(mp[0], 1));
    set<int> st;
    for(int ii = 1; ii <= n; ++ii) st.insert(ii);
    int mex = 1;
    while(mex < n) {
        int l = mp[mex];
        if(l < mp[0]) {
            while(l <= i) {
                st.erase(v[i]);
                --i;
            }
            mex = *st.begin();
            loc.push_back(pair(i + 1, mex));
        }
        else {
            while(j <= l) {
                st.erase(v[j]);
                ++j;
            }
            mex = *st.begin();
            loc.push_back(pair(j - 1, mex));
        }
    }
    for(auto val : loc) ans[val.ff] = 0;
    build();
    int in = 0;
    auto f = [&]() -> int {
        while(in < n && ans[in] == 0) ++in;
        return in;
    };
    ll last = 1;
    int s = INT_MAX, e = INT_MIN;
    if(sz(loc) == 1) cout << last;
    else {
        for(int ii = 1; ii < sz(loc); ++ii) {
            s = min({s, loc[ii].ss, loc[ii - 1].ss});
            e = max({e, loc[ii].ss, loc[ii - 1].ss});
            int num = e - s - 1;
            int sum = query(1, 0, n - 1, s, e);
            debug(sum, num, s, e, ans);
            last = (last * (ncr(sum, num) * fact[num]) % MOD) % MOD;
            while(num > 0) {
                f();
                debug(in);
                ans[in] = 0;
                update(1, 0, n - 1, in, 0);
                --num;
            }
        }
        cout << last;
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    for(ll i = 2; i < N; ++i) fact[i] = fact[i - 1] * i % MOD;
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
