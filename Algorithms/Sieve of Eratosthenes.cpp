/*
    Author : prashant_th18
                            :)
*/
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
// A good algorithm for dinding prime numbers from 1 to n
// link -> https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
void solve()
{
    ll n;
    cin >> n;
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    fl(i, 2, n + 1)
    {
    	if (v[i] && i * i <= n)
    	{
    		// All proper mutiple of i are updated to "false"
    		for(ll j = i * i; j <= n; j += i)
    		{
    			v[j] = false;
    		}
    	}
    }
    fl(i, 0, n + 1)
    if(v[i]) cout << i << nline;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
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