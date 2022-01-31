#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define sz(x) ((int)x.size())
int32_t main() {
    int n; cin >> n;
    unordered_map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int same = 0;
    for(const auto& val : mp)
    {
        if(val.ss > 1) same++;
    }
    int mini = n;
    if(sz(mp) == n) mini = 0;
    for(int i = 0; i < n; ++i)
    {
        int temp = same;
        for(int j = i; j < n; ++j)
        {
            mp[v[j]]--;
            if(mp[v[j]] == 1)
            {
                temp--;
            }
            if(temp == 0)
            {
                mini = min(mini, j - i + 1);
            }
        }
        for(int j = n - 1; j >= i; --j)
        {
            mp[v[j]]++;
        }
    }
    cout << mini;
    return 0;
}
