/*
    Author : prashant_th18
                            :)
*/
// Quick Sort
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
int partition(int a[], int si, int ei)
{
    int cnt = 0;
    for (int i = si; i <= ei; ++i)
    {
        if (a[i] < a[si])
        {
            ++cnt;
        }
    }
    std::swap(a[si], a[cnt + si]);
    int i = si, j = ei;
    int mid = cnt + si;
    while(i != mid && j != mid)
    {
        if (a[i] <= a[mid])
        {
            ++i;
        }
        else if (a[j] >= a[mid])
        {
            --j;
        }
        else
        {
            std::swap(a[i], a[j]);
            ++i, --j;
        }
    }
    return si + cnt;
}
void QuickSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int x = partition(a, si, ei);
    QuickSort(a, si, x - 1);
    QuickSort(a, x + 1, ei);
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
    QuickSort(a, 0, n - 1);
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