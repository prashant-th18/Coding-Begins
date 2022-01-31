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
    int n; cin >> n;
    set<int> st;
    vector<int> v(n);
    for (int &val : v) {
        cin >> val;
        st.insert(val);
    }
    if(n <= 2)
    {
        cout << "YES";
        return 0;
    }
    int s = 0, e = n - 1;
    while(s < e)
    {
        if(v[s] == v[e]) ++s, --e;
        else
        {
            // Asli Kaam yhi se shuru
            // Now either suppose v[s] is deleted or v[e]
            // Supposing v[s] is deleted
            int s1 = s, e1 = e;
            int deleted = v[s1];
            ++s1;
            bool flag = false;
            while(s1 < e1)
            {
                if(v[s1] == v[e1]) ++s1, --e1;
                else
                {
                    if(v[s1] == deleted) ++s1;
                    else if(v[e1] == deleted) --e1;
                    else
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)
            {
                deleted = v[e];
                --e;
                while(s < e)
                {
                    if(v[s] == v[e]) ++s, --e;
                    else
                    {
                        if(v[s] == deleted) ++s;
                        else if(v[e] == deleted) --e;
                        else
                        {
                            cout << "NO";
                            return 0;
                        }
                    }
                }
            }
            cout << "YES";
            return 0;
        }
    }
    cout << "YES";
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
