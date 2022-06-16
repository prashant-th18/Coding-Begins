/*
    Author : prashant_th18
                            :)
*/
// Insertion Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void InsertionSort(vector<int> &v)
{
    int n = (int)v.size();
    for (int i = 1, j; i < n; ++i)
    {
        int no = v[i];
        for(j = i - 1; j >= 0 && v[j] > no; --j)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = no;
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
    InsertionSort(v);
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << space;
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