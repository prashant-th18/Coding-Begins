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
// Using Binary Search with recursion.
int SearchInRotatedArray(vi a, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (a[s] <= a[mid])
    {
        if (a[s] <= key && key <= a[mid])
        {
            return SearchInRotatedArray(a, s, mid - 1, key);
        }
        else
        {
            return SearchInRotatedArray(a, mid + 1, e, key);
        }
    }
    else
    {
        if (a[mid] <= key && key <= a[e])
        {
            return SearchInRotatedArray(a, mid + 1, e, key);
        }
        else
        {
            return SearchInRotatedArray(a, s, mid - 1, key);
        }
    }
}
void solve()
{
    int n, key;
    cin >> n >> key;
    vi v(n);
    fl(i, 0, n) cin >> v[i];
    cout << SearchInRotatedArray(v, 0, n - 1, key);
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