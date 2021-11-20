#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    // cout << fixed << setprecision(0);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //////
    int t = 1;
    // cin >> t; // We are taking test cases
    while (t--)
    {
        ll n; cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first, v[i].second = i;
        vector<int> print(n);
        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        });
        for(int i = 0; i < n; ++i)
        {
            print[v[i].second] = i + 1;
        }
        for(int i = 0; i < n; ++i)
        {
            cout << print[i] << ' ';
        }

    }
    return 0;
}
