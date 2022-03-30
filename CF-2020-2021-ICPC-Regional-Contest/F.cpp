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

int sign(int t)
{
    if(t < 0) return -1;
    return 1;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<array<int, 4>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    auto f = [&](array<int, 4> a, array<int, 4> b) -> bool
    {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    };
    sort(v.begin(), v.end(), f);
    map<tuple<int, int, bool>, int> mp;
    ll sum {};
    for(int i = n - 1; i >= 0; --i)
    {
        debug(v[i][0] , v[i][1], v[i][2], v[i][3]);
        int y = v[i][3] - v[i][1];
        int x = v[i][2] - v[i][0];
        if(x == 0)
        {
            y = (y < 0) ? (-1) : (1);
        }
        else if(y == 0)
        {
            x = (x < 0) ? (-1) : (1);
        }
        else
        {
            int gg = gcd(abs(y), abs(x));
            y /= gg, x /= gg;
        }
        bool iAm = false;
        if(x >= 0)
        {
            iAm = true;
        }
        bool opp = !iAm;
        int tx = -x, ty = -y;
        tuple<int, int, bool> temp  = make_tuple(ty, tx, opp);
        if(mp.count(temp))
        {
            sum += mp[temp];
        }
        mp[make_tuple(y, x, iAm)]++;
    }
    for(auto val : mp)
    {
        debug(get<0>(val.ff), get<1>(val.ff), get<2>(val.ff), val.ss);
    }
    cout << sum;
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
