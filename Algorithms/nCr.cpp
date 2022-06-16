/*
    Author : prashant_th18
                            :)
*/
// C++ program for (nCr)
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
template <typename A>
A nCr(A a, A b)
{
    if(b > a)
    {
        return 0;
    }
    A res = 1;
    b = MIN(b, a - b);
    A j = b;
    for(A i = a; i > a - b; --i)
    {
        res *= i;
        if (j > 0)
        {
            for(; j > 0; --j)
            {
                if (res % j == 0)
                {
                    res /= j;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return res;
}
void solve()
{
    cout << nCr(5, 2);
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