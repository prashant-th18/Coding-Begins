/*
    Author : prashant_th18
                            :)
*/
// Algorithm for finding out all divisors of a number
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define m_p make_pair
#define vl vector<ll>
#define vi vector<int>
#define vpi vector<pi>
#define vpl vector<pl>
#define vd vector<double>
#define pb push_back
#define mll map<ll, ll>
#define be(v) begin(v), end(v)
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline "\n"
#define space " "
void debug(int x){
#ifndef ONLINE_JUDGE 
    cout << "The value is : " << x << nline; 
#endif
}
template <typename A>
A MIN(A a, A b)
{   
    if (a < b) return a;
    return b;
}
template <typename A>
A gcd(A a, A b)
{
    while (b) a%=b, swap(a, b);
    return a;
}
// Time Complexity - O(root(n))
// Space Complexity - O(root(n))
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for(ll i = 1; i <= (ll)sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                v.pb(i);
            }
            else
            {
                v.pb(i), v.pb(n / i);
            }
        }
    }
    sort(be(v)); // Now all divisors are sorted.
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}