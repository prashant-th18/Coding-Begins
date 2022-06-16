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
// Binary Exponentiation
// Time Complexity - O(n)
// Space Complexity - O(1)
ll binaryExponentiation(ll base, ll power)
{
    ll res = 1;
    while(power > 0)
    {
        if (power & 1)
        {
            res *= base;
        }
        base *= base;
        power /= 2;
    }
    return res;
}
//Calculating "base^power" using some binary tricks
void solve()
{
    ll base, power;
    cin >> base >> power;
    cout << binaryExponentiation(base, power);
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