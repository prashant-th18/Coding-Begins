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
/*
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
ll longest(std::vector<ll>& v)
{
    if (v.size() == 0) // boundary case
        return 0;
 
    std::vector<ll> tail(v.size(), 0);
    ll length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < sz(v); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
    return length;
} */
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<ll>& v, ll l, ll r, ll key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
ll longest(std::vector<ll>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<ll> tail(v.size(), 0);
    ll length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] >= tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }
    return length;
}
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll length1 = longest(a);
    ll length2 = longest(b);
    cout << length1 + length2;
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
