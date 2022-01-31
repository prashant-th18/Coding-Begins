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
// *-> KISS*
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
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
const ll inf = 1e12;
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});
int solve() {
    ll div, n; cin >> div >> n;
    vector<ll> dp((int)1e7, inf);
    vector<bool> vis((int)1e7 + 1, false);
    auto fun = y_combinator([&](auto f, ll num) -> ll
    {
        debug(num);

        vis[num] = true;
        if(dp[num] != inf) return dp[num];
        if(num == 1)
        {
            return dp[num] = 0;
        }
        else if(num < 10)
        {
            if(num % div != 0)
            return dp[num] = inf;
            else
            return dp[num] = 1 + f(num / div);
        }
        string a = to_string(num);
        string b = a;
        ll cnt = 0;
        do
        {
            ll newnum = stoll(b);
            if(!vis[newnum]) dp[newnum] = min(dp[newnum], f(newnum));
            if(newnum % div == 0)
            {
                if(!vis[newnum / div]) dp[newnum] = min(dp[newnum], 1 + f(newnum / div));
                else dp[newnum] = min(dp[newnum], 1 + dp[newnum / div]);
            }
            
            dp[num] = min(dp[num], cnt + dp[newnum]);
            
            while(cnt < sz(a) && b[sz(b) - 1] == '0')
            {
                b = b[sz(b) - 1] + b.substr(0, sz(a) - 1); ++cnt;
            }
            if(b == a || cnt >= sz(a)) break;
            b = b[sz(b) - 1] + b.substr(0, sz(a) - 1); ++cnt;
        } while(cnt < sz(a));
        return dp[num];
    });
    ll tt = fun(n);
    cout << dp[n];
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
}
// -> Keep It Simple Stupid!
