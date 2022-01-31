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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    // 0 -> R
    // 1 -> G
    // 2 -> B
    vector<array<int, 3>> v(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            v[i + 1][j] = v[max(i - 2, 0)][j];
            if((j == 0 && s[i] == 'R') || (j == 1 && s[i] == 'G') || (j == 2 && s[i] == 'B')) ++v[i + 1][j];
        }
    }
    vector<string> h {"RGB", "GBR", "BRG"};
    unordered_map<string, int> in;
    in[h[0]] = 0; in[h[1]] = 1; in[h[2]] = 2;
    // abc
    // GBR {1}
    // BRG {2}
    // RGB {3}
    auto f = [&](int index, string tt) -> ll
    {
        ll temp;
        if(tt == "GBR")
        {
            temp = v[max(0, index)][0] + v[max(index - 1, 0)][2] + v[max(index - 2, 0)][1];
        }
        else if(tt == "BRG")
        {
            temp = v[max(index, 0)][1] + v[max(index - 1, 0)][0] + v[max(index - 2, 0)][2];
        }
        else
        {
            temp = v[max(0, index)][2] + v[max(index - 1, 0)][1] + v[max(index - 2, 0)][0];
        }
        return temp;
    };
    auto fort2 = [&](int index, int kk, string tt)
    {
        if(kk % 3 == 0)
        {
            return f(index, tt);
        }
        else if(kk % 3 == 1)
        {
            return f(index, h[(in[tt] + 2) % 3]);
        }
        else
        {
            return f(index, h[(in[tt] + 1) % 3]);
        }
    };
    ll maxx = 1e9;
    ll a = k / 3 + (k % 3 >= 1);
    ll b = k / 3 + (k % 3 == 2);
    ll c = k / 3;
    for(int i = 0; i <= n - k; ++i)
    {
        ll t1;
        ll t2;
        // {1}
        t1 = f(i + k, "RGB"), t2 = fort2(i, k, "RGB"); 
        maxx = min(maxx, a + b + c - (t1 - t2));
        t1 = f(i + k, "GBR"), t2 = fort2(i, k, "GBR");
        maxx = min(maxx, a + b + c - (t1 - t2));
        t1 = f(i + k, "BRG"), t2 = fort2(i, k, "BRG");
        maxx = min(maxx, a + b + c - (t1 - t2));     
    }
    cout << maxx;
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
