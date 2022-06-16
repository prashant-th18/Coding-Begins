/*
    Author : prashant_th18
                            :)
*/
// Counting Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void solve()
{
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++mp[a[i]];
    }
    for(auto val : mp)
    {
        while(val.second != 0)
        {
            cout << val.first << space;
            --val.second;
        }
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