#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<ll> pen(n, 0); // Keeps pending data
    vector<ll> op(n, 0);
    int i = 0, j = m - 1;
    auto ah = [&]() -> void {
        while(i < j) {
            for(int k = 0; k < n - 1; ++k) {
                if(v[k][i] != v[k + 1][i]) return;
            }
            ++i;
        }
    };
    auto bh = [&]() -> void {
        while(i < j) {
            for(int k = 0; k < n - 1; ++k) {
                if(v[k][j] != v[k + 1][j]) return;
            }
            --j;
        }
    };
    ah(); bh();
    // Work on bh first
    while(i != j) {
        ll mini = LLONG_MAX;
        for(int k = 0; k < n; ++k) {
            mini = min(mini, v[k][j]);
        }
        for(int k = 0; k < n; ++k) {
            ll dif = v[k][j] - mini;
            if(dif == 0) continue;
            else {
                pen[k] += dif;
                v[k][j] = mini;
                v[k][j - 1] += dif;
            }
        }
        bh();
        if(i == j) break;
        mini = LLONG_MAX;
        for (int k = 0; k < n; k++) {
            mini = min(mini, v[k][i]);
        }
        for (int k = 0; k < n; k++) {
            ll dif = v[k][i] - mini;
            if(dif == 0) continue;
            else {
                pen[k] -= dif;
                v[k][i] = mini;
                v[k][i + 1] += dif;
            }
        }
        ah();
    }
    set<ll> st;
    for (int ii = 0; ii < n; ii++) {
        st.insert(pen[ii]);
    }
    map<ll, vector<int>> mp;
    for (int ii = 0; ii < n; ii++) {
        mp[pen[ii]].push_back(ii + 1);
    }
    for(auto val : mp) {
        if(sz(val.ss) == 1) {
            cout << val.ss[0] << ' '; break;
        }
    }
    assert(sz(st) == 2);
    cout << *(st.rbegin()) - *(st.begin());
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
