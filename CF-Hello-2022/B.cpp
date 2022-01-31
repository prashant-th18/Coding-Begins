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
struct comp
{
  bool operator()(const tuple<ll, ll, ll, ll>& a, const tuple<ll, ll, ll, ll>& b) const
  {
      if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
        return get<2>(a) < get<2>(b);
  }
};
int solve() {
    int n; cin >> n;
    priority_queue<tuple<ll, ll, ll, ll>> pq; // {a, b} ci, sum
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if(pq.empty())
        {
            pq.push(tuple(a, b, c, c));
            cout << c << '\n';
        }
        else
        {
            bool flag = false;
            while(!pq.empty())
            {
                auto f = pq.top();
                if(get<1>(f) < b)
                {
                    if(get<0>(f) >= a)
                    {
                        pq.pop();
                    }
                    else { flag = true; break; }
                }
                else if(get<1>(f) > b)
                {
                    flag = true;
                    break;
                }
                else
                {
                    if(sz(pq) == 1)
                    {
                        if(get<0>(f) > a) pq.pop();
                        else if(get<0>(f) < a) { flag = true; break; }
                        else
                        {
                            if(get<2>(f) < c) {flag = true; break;}
                            else pq.pop();
                        }
                    }
                    else
                    {
                        if(get<2>(f) > c) pq.pop();
                        else { flag = true; break; }
                    }
                }
            }
                if(sz(pq) == 0)
                {
                    pq.push(tuple(a, b, c, c));
                    cout << c << '\n';
                }
                else
                {
                    pq.push(tuple(a, b, c, get<3>(pq.top()) + c));
                    cout << get<3>(pq.top()) + c << '\n';
                }
        }
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
