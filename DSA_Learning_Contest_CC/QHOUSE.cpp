#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int32_t main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    auto f = [&]() -> bool
    {
        string s; cin >> s;
        if(s == "YES") return true;
        else return false;
    };
    int ans = 0, output = 0, coor = 0;
    int s = 1, e = 1000;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        cout << "? " << mid << ' ' << 0 << endl;
        if(f())
        {
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    ans *= 2;
    output += (ans * ans);
    s = 1, e = 1000;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        cout << "? " << mid << ' ' << ans << endl;
        if(f())
        {
            coor = mid; s = mid + 1;
        }
        else e = mid - 1;
    }
    int yy = 0;
    s = ans + 1, e = 1000;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        cout << "? " << 0 << ' ' << mid << endl;
        if(f())
        {
            yy = mid; s = mid + 1;
        }
        else e = mid - 1;
    }
    yy -= ans;
    output += (yy * coor);
    cout << "! " << output << endl;
    return 0;
}
