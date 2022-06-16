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
// Two pointer method
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    fl(i, 0, n)
    {
        cin >> a[i];
    }
    fl(i, 0, m)
    {
        cin >> b[i];
    }
    int x;
    cin >> x;
    sort(be(a)), sort(be(b));

    // Two pointer method starts :
    // We want to find that pair such that sum is equal to 'x'

    int  i = 0, j = m - 1;
    while(i < n)
    {
        if (a[i] + b[j] > x)
        {
            --j;
        }
        else if (a[i] + b[j] < x)
        {
            ++i;
        }
        else
        {
            cout << a[i] << space << b[j] << nline;
            break;
        }
    }

    // Time Complexity - O(n + m)
    // Space Complexity - O(1)
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