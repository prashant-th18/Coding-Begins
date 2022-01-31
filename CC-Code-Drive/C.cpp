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
int N = 2e6;
vector<bool> primes(N, false);
int solve() {
    // Find spf
    ll num; cin >> num;
    ll n = num;
    for(ll i = 2; i * i <= num; ++i)
    {
        if(num % i == 0)
        {
            n = num / i; break;
        }
    }
    ll ans = 1;
    for(auto val : {2, 3, 5})
    {
        ll cnt = 0;
        while(n % val == 0)
        {
            n /= val; ++cnt;
        }
        ans = ans * (cnt + 1);
    }
    array<int, 8> inc{4, 2, 4, 2, 4, 6, 2 ,6};
    int k = 0;
    for(ll i = 7; i * i <= n; i += inc[k++])
    {
        if(k == 8) k = 0;
        ll cnt = 0;
        while(n % i == 0)
        {
            n /= i; ++cnt;
        }
        ans = ans * (cnt + 1);
    }
    if(n >= 2e6)
    {
        if((int)sqrt(n) == (int)ceil(sqrt(n)) && primes[(int)sqrt(n)]) ans *= 3;
        else if(n != 1) ans *= 4;
    }
    else
    {
        if(primes[n]) ans *= 2;
        else if((int)sqrt(n) == (int)ceil(sqrt(n)) && primes[(int)sqrt(n)]) ans *= 3;
        else if(n != 1)
        {
            ans *= 4;
        }
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    array<int, 8> inc { 4, 2, 4, 2, 4, 6, 2, 6};
    int k = 0;
    primes[2] = primes[3] = primes[5] = true;
    for(ll i = 7; i < N; i += inc[k++])
    {
        if(k == 8) k = 0;
        primes[i] = true;
    }
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
