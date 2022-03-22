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
const int MOD = 1000000007;
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

void p()
{
    cout << "Yes";
}
void n()
{
    cout << "No";
}
// *-> KISS*
int solve() {
    ll x, d; cin >> x >> d;
    ll sq = d * d;
    ll pd = 0; // power of d in "x"
    ll temp = x;
    while(temp % d == 0) temp /= d, ++pd; // Removing all the degree of d from temp, and calculating it
    temp *= d; // Now, temp will be same as "x" after removing (all - 1) degree of "d" from it
    --pd; // Left Degree of "d"
    if(pd == 0)
    {
        // "x" has d of degree one
        n();
        return 0;
        // Because it is never possible to split it into two or more numbers such that
        // those all numbers are beautiful
    }
    // Assume that I have factorised "x" as -> d, d, d, ... , d, temp [!!!!!!!! This is one way]
    // These d are "p" times(left degree of "d")
    // So we have got one way of factorizing "x" in terms of beautiful numbers as shown in second
    // line above from this number
    //
    // How can we get one another way?
    // Cases: 
    // 1.) You may remove some factor from "temp" which is not a multiple of d, and mutiply it 
    // to some other "d", to get some other factorization set. 
    // 
    // 2.)You may factorize a "d" into two numbers and multiply one of them to other "d" and the other
    // to "temp" and now we may get another "factorization set"

    // Factorizing temp
    {
        ll ntemp = temp / d; // Removed the only one "d" present in temp
        // Now when we will factorize ntemp, there will be no factor which is multiple of "d"
        vector<ll> init = {d, temp}; sort(init.begin(), init.end());
        auto ac1 = [&](ll n1, ll n2) -> bool
        {
            vector<ll> tt = {n1, n2};
            sort(tt.begin(), tt.end());
            if(init != tt)
            {
                // Okay one other way found, One way was previously found, so "TWO WAYS ARE FOUND"
                // Therefore, we have got the answer
                return true;
            }
            return false;
        };
        for(ll i = 2; i * i <= ntemp; ++i)
        {
            if(ntemp % i != 0) continue;

            ll f1 = i, f2 = ntemp / i;
            if(ac1(d * f1, f2 * d))
            {
                p(); return 0;
            }
            if(ac1(d * f2, f1 * d))
            {
                p(); return 0;
            }
        }
    }
    // Case 2:
    if(pd == 1)
    {
        // No other d is present where we can send one of our factor
        n(); return 0;
    }
    // Factorizing "d"
    {
        vector<ll> init = {d, temp};
        auto ac2 = [&](ll n1, ll n2) -> bool
        {
            if(n1 % sq == 0 || n2 % sq == 0) return false;

            vector<ll> tt = {n1, n2};
            sort(tt.begin(), tt.end());
            if(init != tt)
            {
                return true;
            }
            return false;
        };
        for(ll i = 2; i * i <= d; ++i)
        {
            if(d % i != 0) continue;

            ll f1 = i, f2 = d / i;
            if(ac2(d * f1, temp * f2))
            {
                p(); return 0;
            }
            if(ac2(d * f2, temp * f1))
            {
                p(); return 0;
            }
            // Or You may give both factors to some "d" if possible
            if(pd >= 3)
            {
                if(ac2(d * f1, d * f2))
                {
                    p(); return 0;
                }
            }
        }
    }
    n();
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
    return 0;
}
// -> Keep It Simple Stupid!
