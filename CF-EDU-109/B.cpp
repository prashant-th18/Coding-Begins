#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for (int t = 0; t < tt; t++) {
        
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(is_sorted(v.begin(), v.end()))
    {
        cout << 0;
    }
    else
    {
        if(v[0] == 1) cout << 1;
        else
        {
            if(v[n - 1] == n) cout << 1;
            else
            {
                if(v[0] == n && v[n - 1] == 1) cout << 3;
                else cout << 2;
            }
        }
    }
    cout << '\n';
    }
    return 0;
}
