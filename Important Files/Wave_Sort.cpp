/*
    Author : prashant_th18
                            :)
*/
// WaveSort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void WaveSort(vector<int> &v)
{
    int n = (int)v.size();
    for (int i = 0; i < n; i += 2)
    {
         if (i > 0 && v[i - 1] > v[i])
         {
             swap(v[i - 1], v[i]);
         }
         if (i < n - 1 && v[i + 1] > v[i])
         {
             swap(v[i + 1], v[i]);
         }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    WaveSort(v);
    for(auto val : v)
    {
        cout << val << space;
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
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}