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
    map<int, int> mp, copy; // by - default all the keys will have value zero!
    while(m--)
    {
        int tt;
        cin >> tt;
        ++mp[tt];
        if ((int)mp.size() == n)
        {
            cout << 1;
            copy.clear(); // clear function is a general function for STL, which is used to clear the container.
            for(auto &val : mp)
            {
                --val.second;
                if (val.second != 0)
                {
                    copy[val.first] = val.second; // map key is accessed with the help of ".first" & it's value is accessed with the help of ".second"
                }
            }
            mp = copy; // map can be copied directly with the help of assignment operator !!
        }
        else
        {
            cout << 0;
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