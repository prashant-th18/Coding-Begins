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

inline ll nxt() { ll _; cin >> _; return _; }

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
    ll x = nxt(), y = nxt();
    string a, b;
    ll xt = x, yt = y;
    while(x != 0)
    {
        a += (x % 2 + '0');
        x /= 2;
    }
    reverse(all(a));
    while(y != 0)
    {
        b += (y % 2 + '0');
        y /= 2;
    }
    reverse(all(b));
    int c1 = count(all(a), '1'), c2 = count(all(b), '1');
    if(c1 == c2 && c1 == 1)
    {
        if(xt != yt)
        {
            cout << "NO";
        }
        else cout << "YES";
        return 0;
    }
    auto add1 = [&](string s) -> string
    {
        s += "1";
        reverse(all(s));
        return s;
    };
    auto remove0 = [&](string s) -> string
    {
        int index = s.rfind('1');
        s = s.substr(0, index + 1);
        return s;
    };
    ///   11111101111110010010101011101110111010010110110011101
    ////  11111101111110010010101011101110111010010110110011101111
    ///
    ///
    ////
    ///
    vector<string> res;
    res.push_back(a);
    string temp = a;
    string oo = a;
    reverse(all(oo));
    res.push_back(oo);
    for (int i = 0; i < 63; i++) {
        temp = add1(temp);
        string other = temp; reverse(all(other));
        res.push_back(other);
        res.push_back(temp);
    }
    a = remove0(a);
    string other1 = a; reverse(all(other1));
    res.push_back(other1);
    res.push_back(a);
    for(int i = 1; i <= 63; ++i)
    {
        a = add1(a);
        string other = a; reverse(all(other));
        res.push_back(other);
        res.push_back(a);
    }
    auto it = find(all(res), b);
    if(it != res.end())
    {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
