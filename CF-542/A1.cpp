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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        if(b > a)
        {
            v[a].push_back(b - a);
        }
        else
        {
            v[a].push_back(n - a + b);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].rbegin(), v[i].rend());
    }
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        if(sz(v[i]) != 0)
        {
            time[i] = (sz(v[i]) - 1) * n + v[i][sz(v[i]) - 1];
        }
    }
    auto inc = [&](int & num) -> void { num = (num + 1) % n; };
    vector<int> result(n);
    for(int i = 0; i < n; ++i)
    {
        if(time[i] != 0)
        {
            int j = i, cnt = 1;
            inc(j);
            int ti = time[i];
            while(j != i)
            {
                if(time[j] != 0 && time[j] > ti - cnt)
                {
                    ti += (time[j] - (ti - cnt));
                }
                ++cnt;
                inc(j);
            }
            result[i] = ti;
        }
    }
    for (int i = 0; i < n; i++) {
        if(time[i] == 0)
        {
            result[i] = INT_MIN;
            int j = i, cnt = 1;
            inc(j);
            while(j != i)
            {
                if(time[j] != 0)
                {
                    result[i] = max(result[i], cnt + time[j]);
                }
                ++cnt;
                inc(j);
            }
        }
    }
    for(auto val : result) cout << val << ' ';
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
