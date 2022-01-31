#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int s = -1, e = -1;
    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
        if(sorted[i] != v[i])
        {
            if(s == -1) s = i, e = i;
            else e = i;
        }
    }
    if(s == -1)
    {
        cout << "yes\n" << 1 << ' ' << 1;
        return 0;
    }
    reverse(v.begin() + s, v.begin() + e + 1);
    if(v == sorted)
    {
        cout << "yes\n" << s + 1 << ' ' << e + 1;
        return 0;
    }
    cout << "no";
}
