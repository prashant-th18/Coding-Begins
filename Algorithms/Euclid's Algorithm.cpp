/*
    Author : prashant_th18
                            :)
*/
// GCD & LCM using Euclid's Algorithm
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
// GCD calculation by Euclid's Algorithm
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}
// LCM calculation by using GCD
int LCM(int a, int b)
{
    return (a * b) / (GCD(a, b));
}
void solve()
{
    int num1, num2;
    cin >> num1 >> num2;
    int gcd = GCD(num1, num2);
    cout << gcd << space << LCM(num1, num2);
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