/*
    Author : prashant_th18
                            :)
*/
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void solve()
{
    
    int n, m;
    cin >> n >> m;
    int chars = 26;
    int a[chars][m];
    for (int i = 0; i < chars; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        string ss;
        cin >> ss;
        for (int j = 0; j < (int)ss.size(); ++j)
        {
            ++a[ss[j] - 97][j];
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        string ss;
        cin >> ss;
        for (int j = 0; j < (int)ss.size(); ++j)
        {
            --a[ss[j] - 97][j];
        }
    }
    // cout << a[0][m - 1] << nline;
    for (int i = 0; i < m; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            if(a[j][i] == 1)
            {
                // cout << j << space << i ;
                cout << char(j + 97);
                break;
            }
        }
    }
    fflush(stdout);
        
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
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}