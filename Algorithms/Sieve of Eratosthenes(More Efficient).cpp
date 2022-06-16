/*
    Author : prashant_th18
                            :)
*/
// Sieve of Eratosthenes (More Efficient)
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
void printPrimes(int n)
{
    vector<bool> v(n + 1, true);
    // 0 & 1 are marked as not prime at the very starting.
    v[0] = v[1] = false;
    // Now we are stating all even numbers from 4 to n as Non-Prime as "2" is a divisor for them.
    for(ll i = 4; i <= n; i += 2)
    {
        v[i] = false;
    }
    // In the below loop, I am iterating over the odd ones only.
    for(ll i = 3; i <= n; i += 2)
    {
        if (v[i] && (i * i) <= n)
        {
            // Below loop is more efficient as it starts from 'i *i' and updates value by (2*i) which
            // makes sense as I am only iterating over the odd numbers, "j" will always be a odd number
            // and if updates them by "i", then (odd + odd = even) and even are obviously non prime
            // so it's no good to iterate over them, so therefore by (2 *i), I am able to ignore them.
            for(ll j = i * i; j <= n; j += (2 * i))
            {
                v[j] = false;
            }
        }
    }
    cout << "All Primes from 1 to " << n << " are : " << nline;
    fl(i, 2, n + 1)
    {
        if(v[i])
        cout << i << nline;
    }
}
void solve()
{
    int n;
    cin >> n;
    printPrimes(n);
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