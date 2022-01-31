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
    string s; cin >> s;
    string temp = "";
    vector<string> one, two;
    auto yt = [&](string s1) -> bool
    {
        if(sz(s1) == 0) return true;
        int cc = 0;
        for (int i = 0; i < sz(s1); i++) {
            cc += ('0' <= s1[i] && s1[i] <= '9');
        }
        if(cc == sz(s1) && (sz(s1) == 1 || s1[0] != '0')) return false;
        return true;
    };
    // Whenever we get . or , or ; we will push string
    for (int i = 0; i <= sz(s); i++) {
        if(i == sz(s) || s[i] == ',' || s[i] == ';')
        {
            if(yt(temp))
            {
                two.push_back(temp);
            }
            else one.push_back(temp);
            temp = "";
        }
        else temp += s[i];
    }
    if(sz(one) == 0) cout << "-" << '\n';
    else
    {
        cout << "\"";
        cout << one[0];
        for(int i = 1; i < sz(one); ++i)
        {
            cout << "," << one[i];
        }
        cout << "\"" << '\n';
    }
    if(two.empty()) cout << "-" << '\n';
    else
    {
       cout << "\"";
       cout << two[0];
       for(int i = 1; i < sz(two); ++i)
       {
           cout << "," << two[i];
       }
       cout << "\"" << '\n';
    }
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
        if(solve())
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
