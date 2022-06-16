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
int SearchInRotatedArray(vi a, int key)
{
    int s = 0, e = (int)a.size() - 1;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            // Key found.
            return mid;
        }
        else if (a[s] <= a[mid])
        {
            if (a[s] <= key && key <= a[mid])
            {
                // it is guaranteed that number is present in this line.
                e = mid - 1;
            }
            else
            {
                // it is possible to move to the second line.
                s = mid + 1;
            }
        }
        else
        {
            if (a[mid] <= key && key <= a[e])
            {
                // this means that number is present at second line for sure.
                s = mid + 1;
            }
            else
            {
                // it is possible to move to the first line.
                e = mid - 1;
            }
        }
    }
    return -1;
}
void solve()
{
    int n, key;
    cin >> n >> key;
    vi v(n);
    fl(i, 0, n) cin >> v[i];
    cout << SearchInRotatedArray(v, key);
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