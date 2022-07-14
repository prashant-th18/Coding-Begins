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

int k;
string p;
vector<int> t;
void build(int in = 1) {
    if(2 * in > k) {
        // Base Case
        if(p[in - 1] == '?') t[in] = 2;
        else t[in] = 1;
    }
    else {
        build(2 * in);
        build(2 * in + 1);
        if(p[in - 1] == '?') t[in] = t[2 * in] + t[2 * in + 1];
        else if(p[in - 1] == '0') t[in] = t[2 * in];
        else t[in] = t[2 * in + 1];
    }
}
void update(int in, char ch, string& order, int c) {
    if(c == sz(order)) {
        // Base Case
        p[in - 1] = ch;
        if(2 * in > k) {
            if(ch == '?') t[in] = 2;
            else t[in] = 1;
        }
        else {
            if(ch == '?') t[in] = t[2 * in] + t[2 * in + 1];
            else if(ch == '0') t[in] = t[2 * in];
            else t[in] = t[2 * in + 1];
        }
    }
    else {
        if(order[c] == '1') {
            update(2 * in + 1, ch, order, c + 1);
        }
        else update(2 * in, ch, order, c + 1);
        if(p[in - 1] == '?') t[in] = t[2 * in] + t[2 * in + 1];
        else if(p[in - 1] == '0') t[in] = t[2 * in];
        else t[in] = t[2 * in + 1];
    }
}
// *-> KISS*
int solve() {
    cin >> k;
    k = (1 << k) - 1;
    cin >> p;
    reverse(all(p));
    t.assign(4 * k, 0);
    for(int i = 0; i < sz(p); ++i) {
        if(p[i] != '?') {
            int c = p[i] - '0';
            c = 1 - c;
            p[i] = c + '0';
        }
    }
    build();
    int q; cin >> q;
    while(q--) {
        int i; cin >> i;
        i = k - i + 1;
        string order;
        while(i >= 1) {
            if(i % 2 == 0) order += "0", i >>= 1;
            else order += "1", i = (i - 1) >> 1;
        }
        reverse(all(order));
        order = order.substr(1);
        debug(order, t);
        char ch; cin >> ch;
        if(ch != '?') ch = '0' + (1 - (ch - '0'));
        int c = 0;
        update(1, ch, order, c);
        cout << t[1] << '\n';
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
