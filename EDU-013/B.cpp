#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    int y; cin >> y;
    auto f = [&](int year) -> int
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? (366) : (365);
    };
    int d = 0, in = f(y);
    while(1)
    {
        d = (d + f(y)) % 7;
        ++y;
        if(f(y) == in && d == 0) break;
    }
    cout << y;
    return 0;
}
// -> Keep It Simple Stupid!
