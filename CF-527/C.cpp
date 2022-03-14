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
    int n; cin >> n;
    vector<pair<string, int>> v(2 * n - 2);
    for (int i = 0; i < sz(v); i++) {
        cin >> v[i].ff; // string
        v[i].ss = i;
    }
    auto srt = [&](string a, string b) -> bool
    {
        if(sz(a) != sz(b))
        return sz(a) < sz(b);
        return a < b;
    };
    map<int, char> mp;
    sort(v.begin(), v.end(), [&](pair<string, int> a, pair<string, int> b) { 
            if(sz(a.ff) != sz(b.ff))
            return sz(a.ff) < sz(b.ff);
            return a.ff < b.ff;
            });
    auto assume = [&](int index) -> bool
    {
        string s = v[index].ff;
        if(index + 1 < sz(v)) s += v[index + 1].ff[sz(v[index + 1].ff) - 1];
        else s += v[index - 1].ff[sz(v[index - 1].ff) - 1];
        vector<string> temp, prefix, suffix;
        for(int i = 0; i < sz(s) - 1; ++i)
        {
            temp.push_back(s.substr(0, i + 1));
            prefix.push_back(s.substr(0, i + 1));
            temp.push_back(s.substr(i + 1, sz(s) - i));
            suffix.push_back(s.substr(i + 1, sz(s) - i));
        }
        sort(temp.begin(), temp.end(), srt);
        sort(prefix.begin(), prefix.end(), srt);
        sort(suffix.begin(), suffix.end(), srt);
        vector<string> tt;
        for(int i = 0; i < sz(v); ++i) tt.push_back(v[i].ff);
        sort(tt.begin(), tt.end(), srt);
        for(int i = 0; i < sz(temp); ++i)
        {
            if(temp[i] != tt[i]) return false;
        }
        int i = 0, j = 0;
        while(i < sz(prefix) || j < sz(suffix))
        {
            if(i < sz(prefix) && j < sz(suffix))
            {
                if(prefix[i] == v[i + j].ff)
                {
                    mp[v[i + j].ss] = 'P';
                    ++i;
                }
                else
                {
                    mp[v[j + i].ss] = 'S';
                    ++j;
                }
            }
            else if(i < sz(prefix))
            {
                mp[v[i + j].ss] = 'P';
                ++i;
            }
            else
            {
                mp[v[j + i].ss] = 'S';
                ++j;
            }
        }
        return true;
    };
    bool flag = assume(sz(v) - 1);
    flag = assume(sz(v) - 2);
    for(auto val : mp) cout << val.ss;
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
    return 0;
}
// -> Keep It Simple Stupid!
