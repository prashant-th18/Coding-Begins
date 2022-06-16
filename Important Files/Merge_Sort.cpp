/*
    Author : prashant_th18
                            :)
*/
// Merge Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void merge(int a[], int si, int ei)
{
    int b[ei - si + 1] {0};
    int i = si;
    int j = (si + ei) / 2 + 1;
    int mid = j;
    int k = 0;
    while(1)
    {
        if (i < mid && (j > ei || a[i] <= a[j]))
        {
            b[k++] = a[i++];
        }
        else if (j <= ei && (i == mid || a[j] <= a[i]))
        {
            b[k++] = a[j++];
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        // cout << b[i] << space;
        a[si + i] = b[i];
    }
    // cout << endl;
}
void merge_sort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    merge_sort(a, si, mid);
    merge_sort(a, mid + 1, ei);
    merge(a, si, ei);
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << space;
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