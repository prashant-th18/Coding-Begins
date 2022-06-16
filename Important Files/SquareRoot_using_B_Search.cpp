/*
    Author : prashant_th18
                            :)
*/
// Finding Square Root using BinarySeach
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
double squareRoot(int n, int prec)
{
    // Binary Search used below
    int s = 0, e = n;
    int mid, integerPart;
    while(s <= e)
    {
        mid = (s + e) / 2;
        if (mid*mid == n)
        {
            integerPart = mid;
            break;
        }
        else if (mid*mid < n)
        {
            integerPart = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    // Binary Search code end here, and we got the integer part.
    double answer = integerPart, inc = 0.1;
    while(prec--)
    {
        double d = answer;
        while(d * d <= n)
        {
            d = d + inc;
        }
        answer = d - inc;
        inc *= 0.1;
    }
    return answer;
}
void solve()
{
    int n, p;
    cin >> n >> p;
    cout << fixed << setprecision(p);
    cout << squareRoot(n, p);
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