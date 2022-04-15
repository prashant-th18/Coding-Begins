#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll a, b, c; cin >> a >> b >> c;
    ll mini = min({a / 3, b / 2, c / 2});
    a -= mini * 3; b -= mini * 2; c -= mini * 2;
    ll days = 7 * mini, pre = days;
    for(int st = 0; st < 7; ++st)
    {
        ll extra = pre;
        int A = a, B = b, C = c;
        int cnt = 0, s = st;
        while(cnt < 7)
        {
            if(s == 0 || s == 1 || s == 4)
            {
                if(A == 0) break;
                else --A;
            }
            else if(s == 2 || s == 6)
            {
                if(B == 0) break;
                else --B;
            }
            else
            {
                if(C == 0) break;
                else --C;
            }
            ++cnt;
            s = (s + 1) % 7;
        }
        days = max(days, extra + cnt);
    }
    cout << days;
    return 0;
}
