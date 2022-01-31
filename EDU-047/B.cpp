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
    /////////////////////
    //   WRONG ANSWER  //
    /////////////////////
    string s; cin >> s;
    deque<int> two;
    vector<int> zero;
    unordered_map<int, int> mp;
    for (int i = 0; i < sz(s); i++) {
        if(s[i] == '0') { zero.push_back(i); mp[i] = i - 1;}
        else if(s[i] == '2') two.push_back(i);
    }
    // If after lower_bound, we get st.end() then keep other variable
    int last = sz(s) - 1;
    while(!two.empty())
    {
        int temp = two.back();
        auto it = lower_bound(all(zero), temp);
        if(it == zero.end())
        {
            swap(s[temp], s[last--]);
        }
        else
        {
            swap(s[temp], s[mp[*it]--]);
        }
        two.pop_back();
    }
    // 2's work done!
    // Let's do work on 0
    two.clear();
    deque<int> one;
    zero.clear(); last = sz(s) - 1; mp.clear();
    for (int i = 0; i < sz(s); i++) {
        if(s[i] == '2'){ two.push_back(i); mp[i] = i - 1;}
        else if(s[i] == '1') one.push_back(i);
    }
    while(!one.empty())
    {
        int temp = one.back();
        auto it = lower_bound(all(two), temp);
        if(it == two.end())
        {
            swap(s[temp], s[last--]);
        }
        else
        {
            swap(s[temp], s[mp[*it]--]);
        }
        one.pop_back();
    }
    cout << s;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
