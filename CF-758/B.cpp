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
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

inline ll nxt() { ll x; scanf("%lld", &x); return x; }

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}
// *-> KISS*
int solve() {
    int n; cin >> n;
    int maxx, minn; cin >> maxx >> minn;
    if(abs(maxx - minn) >= 2)
    {
        cout << -1;
        return 0;
    }
    if(maxx == 0 && minn == 0)
    {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        return 0;
    }
    auto check = [&](vector<int> z)
    {
        for (int i = 0; i < sz(z); i++) {
            if(z[i] < 1 || z[i] > n)
            {
                return false;
            }
        }
        return true;
    }
    // maxx > minn
    // DUDUD...
    // else if(minn > maxx)
    // UDUDU....
    // else DUDU
    string res = "";
    if(maxx == minn)
    {
        res += "D";
        for (int i = 0; i < maxx; i++) {
            res += "UD";
        }
        res += "U";
        int lc = 1, c = maxx + 2;
        vector<int> help;
        for (int i = 0; i < sz(res); i++) {
            if(c > n)
            {
                cout << -1;
                return 0;
            }
            if(!(i & 1))
            {
                help.push_back(lc++);
            }
            else help.push_back(c++);

        }
        while(c <= n) help.push_back(c++);
        if(sz(help) != n)
        {
            cout << -1;
            return 0;
        }
        if(!check(help))
        {
            cout << -1;
            return 0;
        }
        for(const auto& val : help) cout << val << ' ';
    }
    else if(maxx > minn)
    {
        res += "D";
        for(int i = 0; i < maxx; ++i)
        {
            res += "UD";
        }
        int c = n;
        int lc = c - maxx;
        vector<int> help;
        for (int i = 0; i < sz(res); i++) {
            if(lc <= 0)
            {
                cout << -1;
                return 0;
            }
            if(!(i & 1))
            {
                help.push_back(lc--);
            }
            else help.push_back(c--);
        }
        while(lc >= 1)
        {
            help.push_back(lc--);
        }
        if(sz(help) != n)
        {
            cout << -1;
            return 0;
        }
        if(!check(help))
        {
            cout << -1;
            return 0;
        }
        for(const auto& val : help) cout << val << ' ';
    }
    else
    {
        res += "U";
        for(int i = 0; i < minn; ++i)
        {
            res += "DU";
        }
        int c = 1;
        int uc = minn + c;
        vector<int> help;
        for (int i = 0; i < sz(res); i++) {
            if(uc > n)
            {
                cout << -1;
                return 0;
            }
            if(!(i & 1))
            {
                help.push_back(uc++);
            }
            else
            {
                help.push_back(c++);
            }
        }
        while(uc <= n)
        {
            help.push_back(uc++);
        }
        if(sz(help) != n)
        {
            cout << -1;
        }
        else
        {
            if(!check(help))
            {
                cout << -1;
                return 0;
            }
            for(auto val : help) cout << val << ' ';
        }
    }
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
}
// -> Keep It Simple Stupid!
