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
const int MOD = 998244353;
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


#define pii pair<int, int>
const int N = 1e6;
vector<ll> fact(N, 1);
ll ans1(vector<int>& v) {
    vector<ll> temp;
    int i = 0, j = 0, n = sz(v);
    int cnt = 0;
    while(j < n) {
        if(v[j] == v[i]) ++j, ++cnt;
        else {
            temp.push_back(cnt);
            cnt = 1;
            i = j;
            j++;
        }
    }
    temp.push_back(cnt);
    ll ans = 1;
    for(auto val : temp) {
        ans = ans * fact[val] % MOD;
    }
    return ans;
}
ll ans2(vector<pii>& v) {
    for (int i = 1; i < sz(v); i++) {
        if(v[i].ff < v[i - 1].ff) return 0;
        if(v[i].ss < v[i - 1].ss) return 0;
    }
    vector<ll> temp;
    int j = 1, n = sz(v);
    int cnt = 1;
    while(j < n) {
        if(v[j].ff == v[j - 1].ff && v[j].ss == v[j - 1].ss) ++cnt, ++j;
        else if (v[j].ff >= v[j - 1].ff && v[j].ss >= v[j - 1].ss) {
            temp.push_back(cnt);
            cnt = 1; ++j;
        }
    }
    temp.push_back(cnt);
    ll ans = 1;
    for (int i = 0; i < sz(temp); i++) {
        ans = ans * fact[temp[i]] % MOD;
    }
    return ans;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> f, s;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
        f.push_back(v[i].ff);
        s.push_back(v[i].ss);
    }
    sort(f.begin(), f.end()); sort(s.begin(), s.end());
    sort(v.begin(), v.end());
    ll a = ((ans1(f) + ans1(s)) % MOD - ans2(v) + MOD) % MOD;
    ll b = fact[n];
    cout << (b - a + MOD) % MOD;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    for(ll i = 2; i < N; ++i) {
        fact[i] = i * fact[i - 1] % MOD;
    }
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
