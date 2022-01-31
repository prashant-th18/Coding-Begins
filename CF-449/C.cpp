#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
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

inline ll nxt() { ll x; scanf("%lld", &x); return x; }

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
    ll n, k, q; cin >> q;
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string first = "What are you doing while sending ";
    string second = "? Are you busy? Will you send ";
    string third = "?";
    string help = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
    debug(sz(f0));
    debug(sz(first));
    debug(sz(second));
    debug(sz(third));
    int temp = sz(help) + sz(first) + sz(second) + sz(third) + sz(help) + 4;
    debug(temp);
    ll start = 75;
    function<bool(ll i)> return_me = [&](ll i) -> bool
    {
        if(i == 0)
        {
            if(k < sz(f0))
            {
                cout << f0[k];
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            debug(i);
            debug(k);
            if(k < sz(first))
            {
                cout << first[k];
                return true;
            }
            else if(k == sz(first))
            {
                cout << "\"";
                return true;
            }
            else
            {
                ll extra = 68, my_number;
                ll uff = i - 1;
                if(uff == 0)
                {
                    my_number = start;
                }
                else 
                {
                    if(uff < 56)
                    my_number = ((1LL << uff) - 1) * extra + (1LL << uff) * start;
                    else my_number = LLONG_MAX;
                }
                debug(my_number);
                k -= sz(first); --k;
                if(k < my_number)
                {
                    return_me(i - 1);
                    return true;
                }
                else if(k == my_number)
                {
                    cout << "\"";
                    return true;
                }
                k -= (my_number + 1);
                if(k < sz(second))
                {
                    cout << second[k];
                    return true;
                }
                else if(k == sz(second))
                {
                    cout << "\"";
                    return true;
                }
                else
                {
                    k -= sz(second); --k;
                    if(k < my_number)
                    {
                        return_me(i - 1);
                        return true;
                    }
                    else if(k == my_number)
                    {
                        cout << "\"";
                        return true;
                    }
                    k -= (my_number + 1);
                    if(k == 0)
                    {
                        cout << third; return true;
                    }
                    else if(k == 1 && i != n)
                    {
                        cout << "\""; return true;
                    }
                    else cout << ".";
                    return true;
                }
            }
        }
    };
    while(q--)
    {
        cin >> n;
        cin >> k; --k;
        if(!return_me(n))
        {
            cout << ".";
        }
    }
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
