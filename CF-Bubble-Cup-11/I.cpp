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

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

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
    unordered_map<string, int> mp, own;
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<int> occ(26);
        for (int j = 0; j < sz(s); j++) {
            occ[s[j] - 97]++;
        }
        for(char ch = 'a'; ch <= 'z'; ++ch)
        {
            if(occ[ch - 97] & 1)
            {
                v[i] += ch;
            }
        }
        mp[v[i]]++;
        own[v[i]]++;
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if(sz(v[i]) == 0)
        {
            cnt += max(0, own[v[i]] - 1);
            own[v[i]]--;
        }
        else
        {
            cnt += max(0, own[v[i]] - 1); 
            own[v[i]]--;
            for(int j = 0; j < sz(v[i]); ++j)
            {
                string nn = "";
                for(int k = 0; k < sz(v[i]); ++k)
                {
                    if(k == j) continue;
                    else
                    {
                        nn += v[i][k];
                    }
                }
                cnt += mp[nn];
            }
        }
    }
    cout << cnt;
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
