#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    while(s.find(",") != string :: npos)
    {
        int index = s.find(",");
        s.replace(index, 1, " ");
    }
    cout << s;
}
