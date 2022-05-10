#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a *= 60 * 60;
    a += b * 60;
    c *= 60 * 60;
    c += (d * 60 + 1);
    if(a < c) cout << "Takahashi";
    else cout << "Aoki";
    return 0;
}
