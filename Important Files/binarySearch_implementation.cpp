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
#define m_p make_pair()
#define vl vector<ll>
#define vi vector<int>
#define vpi vector<pi>
#define vpl vector<pl>
#define vd vector<double>
#define pb push_back
#define mll map<ll, ll>
#define be(v) begin(v), end(v)
#define fl(si, ei) for(ll i = si; i < ei; ++i)
#define nline "\n"
#define space " "
void debug(int x){
#ifndef ONLINE_JUDGE 
    cout << "The value is : " << x << nline; 
#endif
}
int binarySearch(vector<int> v, int key)
{
    int si = 0, ei = (int)v.size() - 1;
    int mid;
    // if si > ei, this means that si is telling me that number is present at index >= si 
    // & ei is telling me that number is present at index <= ei
    // Since both statements are contradicting, this means that number is "not present".
    while(si <= ei) 
    {
        mid = (si + ei) / 2;
        if (v[mid] == key)
        {
            // number is found, therefore returning mid.
            return mid;
        }
        else if (v[mid] < key)
        {
            // number is greater than mid, so updating si to mid + 1, so that now we only need to
            // search from mid + 1 to ei
            si = mid + 1;
        }
        else
        {
            // number is less than mid, so updating ei to mid - 1, so that we only need to seach 
            // from si to mid - 1
            ei = mid - 1;
        }
    }
    // not present
    return -1;
}
void solve()
{
    int n, elem;
    cin >> n >> elem;
    vi a(n);
    fl(0, n) cin >> a[i];
    sort(be(a));
    int searchIndex = binarySearch(a, elem);
    if (searchIndex != -1)
    {
        cout << elem << " is present at index " << searchIndex << nline;
    }
    else
    {
        cout << elem << " is not present" << nline;
    }
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