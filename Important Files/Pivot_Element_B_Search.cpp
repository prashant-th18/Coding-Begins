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
int pivotElement(vi a, int s, int e)
{
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if (mid - 1 >= s && a[mid] < a[mid - 1])
        {
            // the "mid" element is smaller than the previous, means pivot element is "mid - 1".
            return mid - 1;
        }
        if (mid + 1 <= e && a[mid + 1] < a[mid])
        {
            // the "mid" element is greater than next one, therefore pivot element is "mid".
            return mid;
        }
        if (a[s] >= a[mid])
        {
            // we do this because now we got to know that left part is unsorted, means pivot element
            // will be in the left side.
            e = mid - 1;
        }
        else
        {
            // means unsorted part is in the right part so, go to the right part.
            s = mid + 1;
        }
    }
    // Pivot not found, means graph is strictly increasing.
    return -1;
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    fl(i, 0, n) cin >> v[i];
    cout << pivotElement(v, 0, n - 1);
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