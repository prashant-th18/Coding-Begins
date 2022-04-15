#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        ll a, b, k; cin >> a >> b >> k;
        ll d = (k / 2) * (a - b);
        if(k & 1) d += a;
        cout << d << '\n';
   }
    return 0;
}
