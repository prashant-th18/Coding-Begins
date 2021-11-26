#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for (int i = 0; i < tt; i++) {
    int n; cin >> n;
    string s; cin >> s;
    int cc = count(s.begin(), s.end(), '0');
    if(cc == 1)
    {
        cout << "BOB\n";   
    }
    else
    {
        if(cc & 1)
        {
            cout << "ALICE\n";
        }
        else cout << "BOB\n";
    }
            
}
    return 0;
}
