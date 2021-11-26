#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--)
    {
        ll a, b; cin >> a >> b;
        if(b == 1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES\n";
            if(b == 2)
            {
                cout << a << ' ' << a * 3 << ' ' << a * 4;
            }
            else
            {
                cout << a << ' ' << a * (b - 1) << ' ' << a * b;
            }
        }
        cout << '\n';
    }
    return 0;
}
