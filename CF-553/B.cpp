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
    int n = nxt(), m = nxt();
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<vector<int>>> bits(n, vector<vector<int>>(11));
    auto bits1 = bits;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll k = 0;
            ll temp = v[i][j];
            while(temp)
            {
                if(temp & 1)
                {
                    bits[i][k].push_back(j);
                }
                else bits1[i][k].push_back(j);
                temp >>= 1;
                ++k;
            }
            while(k < 11)
            {
                bits1[i][k++].push_back(j);
            }
        }
    }
    for (int i = 0; i < 11; i++) {
        int c0 {}, cfull {};
        for (int j = 0; j < n; j++) {
            if(sz(bits[j][i]) == m) ++cfull;
            else if(sz(bits[j][i]) == 0) ++c0;
        }
        if(cfull & 1) // Always Possible
        {
            debug(i);
            cout << "TAK\n";
            for (int j = 0; j < n; j++) {
                if(sz(bits[j][i]) == m) cout << bits[j][i][0] + 1 << '\n';
                else
                {
                   cout << bits1[j][i][0] + 1 << '\n'; 
                }
            }
            return 0;
        }
        else if(c0 != n - cfull)
        {
            debug(c0);
            debug(cfull);
            debug(i + 1000);
            bool flag = true;
            cout << "TAK\n";
            for (int j = 0; j < n; j++) {
                if(sz(bits[j][i]) == m) cout << bits[j][i][0] + 1 << '\n';
                else if(sz(bits[j][i]) == 0)
                {
                    cout << bits1[j][i][0] + 1 << '\n';
                }
                else
                {
                    if(flag)
                    {
                        cout << bits[j][i][0] + 1 << '\n';
                        flag = false;
                    }
                    else cout << bits1[j][i][0] + 1 << '\n';
                }
            }
            return 0;
        }
    }
    cout << "NIE";
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
