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
    ll n, l, r, ss; cin >> n >> l >> r >> ss;
    vector<ll> v(n);
    --l, --r;
    ll rem = (ss % (r - l + 1));
    if(ss / (r - l + 1) == 0)
    {
        debug(2);
        cout << -1;
        return 0;
    }
    for(int i = r; i >= l; --i)
    {
        v[i] = ss / (r - l + 1) + (rem-- > 0);
    }
    int s = l, e = r;
    while(s < e)
    {
        if(v[s] == 1)
        {
            ++s; continue;
        }
        if(v[e] == n) { --e; continue; }
        if(s == l && e == r)
        {
            v[s]--; v[e]++;
        }
        else if(s == l)
        {
            if(v[e] + 1 == v[e + 1]) --e;
            else if(v[e] == v[e + 1]) { v[e]--; v[s]++; }
            else
            {
                v[s]--; v[e]++;
            }
        }
        else if(e == r)
        {
            if(v[s] - 1 == v[s - 1]) ++s;
            else if(v[s] == v[s - 1]) { v[s]++; v[e]--; }
            else
            {
                v[s]--; v[e]++;
            }
        }
        else
        {
            if(v[s] - 1 == v[s - 1]) ++s;
            else if(v[e] + 1 == v[e + 1]) --e;
            else if(v[s] == v[s - 1]) v[s]++, v[e]--;
            else if(v[e] == v[e + 1]) v[e]--, v[s]++;
            else
            {
                v[s]--; v[e]++;
            }
        }
    }
    sort(v.begin() + l, v.begin() + r + 1);
    debug(v);
    for(int i = l; i < r; ++i)
    {
        if(v[i] == v[i + 1])
        {
            cout << -1;
            return 0;
        }
    }
    if(v[r] > n)
    {
        debug(1);
        cout << -1;
        return 0;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for(int i = l; i <= r; ++i)
    {
        st.erase(v[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        if(l <= i && i <= r) continue;
        else
        {
            v[i] = *st.begin();
            st.erase(st.begin());
        }
    }
    for(const auto& val : v) cout << val << ' ';
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
