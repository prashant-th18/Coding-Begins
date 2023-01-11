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
using pll = pair<ll, ll>;


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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct comp {
    bool operator()(const array<ll, 3>& a, const array<ll, 3>& b) const {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
};
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    auto get = [&](ll d) {
        int in = upper_bound(all(v), d) - begin(v);
        ll dis = min(v[in] - d, d - v[in - 1]);
        return dis;
    };
    set<array<ll, 3>, comp> st;
    for(int i = 1; i < n; ++i) {
        if(v[i - 1] + 1 == v[i]) continue;
        ll dif = v[i - 1] + v[i];
        ll mini = dif & 1 ? get((v[i - 1] + v[i]) / 2 + 1) : LLONG_MAX;
        st.insert({min(get((v[i - 1] + v[i]) >> 1), mini), v[i - 1] + 1, v[i] - 1});
    }
    ll sum = 0;
    vector<ll> ans;
    while(!st.empty() && m) {
        --m;
        array<ll, 3> f = *st.begin(); st.erase(st.begin());
        sum += f[0];
        ll mid = (f[1] + f[2]) >> 1;
        ans.push_back(mid);
        if(f[1] != mid) {
            ll dif = f[1] + mid - 1;
            ll mini = dif & 1 ? get((f[1] + mid - 1) / 2 + 1) : LLONG_MAX;
            st.insert({min(mini, get((f[1] + mid - 1) >> 1)), f[1], mid - 1});
        }
        if(f[2] != mid) {
            ll dif = mid + 1 + f[2];
            ll mini = dif & 1 ? get((mid + 1 + f[2]) / 2 + 1) : LLONG_MAX;
            st.insert({min(mini, get((mid + 1 + f[2]) >> 1)), mid + 1, f[2]});
        }
    }
    ll x = v[0] - 1, y = v[n - 1] + 1;
    while(m) {
        --m;
        ll d1 = abs(v[0] - x), d2 = abs(y - v[n - 1]);
        if(d1 < d2) {
            ans.push_back(x);
            sum += d1;
            --x;
        }
        else ans.push_back(y), sum += d2, ++y;
    }
    cout << sum << '\n';
    for(auto& val : ans) cout << val << ' ';
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

