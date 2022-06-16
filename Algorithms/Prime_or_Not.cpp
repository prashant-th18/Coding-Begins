/*
    Author : prashant_th18
                            :)
*/
// Program to see whether number is prime or not.
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
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Number is 1";
        return;
    }
    // If you examine closely, you can get to know about all the divisors if you iterate till root(n).
    fl(i, 2, (ll)(sqrt(n)))
    {
        if (n % i == 0)
        {
            cout << "NOT Prime";
            return;
        }
    }
    cout << "PRIME";
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