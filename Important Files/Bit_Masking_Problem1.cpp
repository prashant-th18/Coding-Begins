/*
    Author : prashant_th18
                            :)
*/
// Given a vector containing elements in which only two elements are occurring once, 
// and all other are occurring twice, find those two numbers, and print in ascending order!
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
void debug(int x) {
#ifndef ONLINE_JUDGE
    cout << "The value is : " << x << nline;
#endif
}
int find_ith_bit(int number, int i)
{
    return ((number >> i) & 1);
}
void solve()
{
    int n, res = 0;
    cin >> n;
    vi v(n);
    fl(i, 0, n)
    {
        cin >> v[i];
        res ^= v[i];
    }
    int cnt = 0;
    int tt = res;
    while (tt > 0)
    {
        if (tt & 1)
        {
            break;
        }
        tt >>= 1;
        ++cnt;
    }
    int firstNumber = 0;
    fl(i, 0, n)
    {
        if (find_ith_bit(v[i], cnt))
        {
            firstNumber ^= v[i];
        }
    }
    cout << min(firstNumber, (res ^ firstNumber)) << space << max(firstNumber, (res ^ firstNumber));

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