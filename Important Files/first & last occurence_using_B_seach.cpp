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
// First occurence of a number using binary search
int firstOccurence_B_search(vi v, int key)
{
    int si = 0, ei = (int)v.size() - 1;
    int mid, ans = -1;
    while(si <= ei)
    {
        mid = (si + ei) / 2;
        if (v[mid] == key)
        {
            // if found, i will update answer and put "ei = mid - 1", so as to see if there's any other 
            // occurence before "ans"
            ans = mid;
            ei = mid - 1;
        }
        else if (v[mid] < key)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return ans;
}
// Last occurence of a number using binary search
int lastOccurence_B_search(vi v, int key)
{
    int si = 0, ei = (int)v.size() - 1;
    int mid, ans = -1;
    while(si <= ei)
    {
        mid = (si + ei) / 2;
        if (v[mid] == key)
        {
            // if found, i will update answer and put "si = mid + 1", so as to see if there's any other 
            // occurence after "ans"
            ans = mid;
            si = mid + 1;
        }
        else if (v[mid] < key)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return ans;
}
void solve()
{
    int n, key;
    cin >> n >> key;
    vi v(n);
    fl(0, n) cin >> v[i];
    cout << firstOccurence_B_search(v, key) << space << lastOccurence_B_search(v, key) << nline;
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