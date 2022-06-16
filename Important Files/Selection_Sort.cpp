/*
    Author : prashant_th18
                            :)
*/
// Selection Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void SelectionSort(vector<int> &v)
{
    int n = (int)v.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int mini = v[i];
        int mindex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (v[j] < mini)
            {
                mini = v[j];
                mindex = j;
            }
        }
        if (mindex != i)
        {
            v[i] = v[i] + v[mindex];
            v[mindex] = v[i] - v[mindex];
            v[i] = v[i] - v[mindex];
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
    SelectionSort(v);
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