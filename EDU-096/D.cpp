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
    string s; cin >> s;
    set<pair<int, int>> st;
    vector<int> help;
    int cnt = 1, c = 0;
    for(int i = 1; i < n; ++i)
    {
        if(s[i] == s[i - 1])
        {
            ++cnt;
        }
        else
        {
            st.insert({-cnt, c++});
            help.push_back(cnt);
            cnt = 1;
        }
    }
    int op = 0;
    st.insert({-cnt, c++});
    help.push_back(cnt);
    for(int i = 0; i < c; ++i)
    {
        debug(help[i]);
        if(help[i] == 1)
        {
            ++op;
            auto f = *(st.begin());
            if(f.first != -1)
            {
                st.erase({-help[i], i});
                help[i] = 0;
                help[f.second]--;
                f.first++;
                st.erase(st.begin());
                st.insert(f);
            }
            else
            {
                st.erase(st.begin());
                help[i]--;
                if(sz(st) == 0)
                {
                    break;
                }
                f = *(st.rbegin());
                help[f.second]--;
                st.erase(f);
            }
        }
        else if(help[i] > 1)
        {
            ++op;
            auto f = st.find({-help[i], i});
            help[i] = 0;
            st.erase(f);
        }
    }
    for(int i = 0; i < c; ++i){ 
        assert(help[i] == 0);
    }
    cout << op;
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
