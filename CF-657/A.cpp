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
#define debug(x) cout << "----------------" << endl << #x << " : "; _print(x); cout << "-------------" << '\n';
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
    int n, occ {}; cin >> n;
    string s; cin >> s;
    vector<set<pair<int, char>>> v;
    string same = "abacaba";
    for (int i = 0; i < n - 6; i++) {
        string temp = s.substr(i, 7);
        if(temp == same) ++occ;
        set<pair<int, char>> tt;
        int j = 0;
        bool flag = true;
        while(j < 7)
        {
            if(temp[j] == '?') tt.insert(pair(i + j, same[j]));
            else
            {
                if(temp[j] != same[j])
                {
                    flag = false;
                    break;
                }
            }
            ++j;
        }
        if(flag)
        {
           if(sz(tt) > 0) v.push_back(tt); 
        }
    }
    if(occ > 1)
    {
        cout << "No";
        return 0;
    }
    if(occ == 1)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
           if(s[i] == '?') cout << 'z';
           else cout << s[i];
        }
        return 0;
    }
    if(sz(v) > 0)
    {
        sort(v.begin(), v.end(), [&](set<pair<int, char>> a, set<pair<int, char>> b) {
                return sz(a) < sz(b);
                });
        int in = -1;
        bool possible = false;
        for (int i = 0; i < sz(v); i++) {
            bool check = true;
            for (int j = 0; j < sz(v); j++) {
                if(i == j) continue;
                if(v[i] == v[j]) { check = false; break; }
            }
            if(check)
            {
                in = i;
                possible = true;
                break;
            }
        }
        if(possible)
        {
            for(auto val : v[in])
            {
                s[val.ff] = val.ss;
            }
            cout << "Yes\n";
            for(auto val : s)
            {
                if(val == '?') cout << 'z';
                else cout << val;
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef LOCAL
            cout << '\n' << "##################";
        #endif
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
// -> Keep It Simple Stupid!
