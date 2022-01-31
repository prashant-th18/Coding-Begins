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
    int n, k; cin >> n >> k;
    vector<int> copyy(n);
    for (int i = 0; i < n; i++) {
        cin >> copyy[i];
    }
    vector<int> v = copyy;
    int cnt = count(all(copyy), 0);
    if(cnt < 1)
    {
        cout << -1; return 0;
    }
    /*if(k == 0)
    {
        vector<int> res(n);
        iota(all(res), 1);
        for(auto val : res) cout << val << ' ';
        return 0;
    }*/
    set<int> st; // index
    vector<int> ans(n);
    int first = 1;
    for(int i = 0; i < n; ++i) if(copyy[i] == 0) { st.insert(i); }
    auto dec = [&](auto in) -> int
    {
        return (in - 1 + n) % n;  
    };
    while(sz(st) != 0)
    {
        set<int> newset;
        while(sz(st) != 0)
        {
            int ind = *st.begin(); st.erase(st.begin());
            ans[ind] = first++;
            int i = dec(ind);
            int c = 0;
            while(c < k)
            {
                if(copyy[i] != 0)
                {
                    --copyy[i];
                    if(copyy[i] == 0)
                    {
                        newset.insert(i);   
                    }
                }
                i = dec(i);
                ++c;
            }
        }
        st = newset;
    }
    if(first <= n)
    {
        cout << -1;
    }
    else
    {
        for(int i = 0; i < n; ++i)
        {
            int j = (i + 1) % n;
            int c = 0, cntt = 0;
            while(c < k)
            {
                if(ans[i] > ans[j]) ++cntt;
                j = (j + 1) % n;
                ++c;
            }
            if(cntt != v[i])
            {
                cout << -1; return 0;
            }
        }
        for(auto val : ans) cout << val << ' ';
    }
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
