#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
// *-> KISS*
int32_t main() {
    string s; cin >> s;
    string a, b, c;
    a += s[0]; a += s[1]; a += s[2];
    b += s[1]; b += s[2]; b += s[0];
    c += s[2]; c += s[0]; c += s[1];
    cout << stoll(a) + stoll(b) + stoll(c);
    return 0;
}
// -> Keep It Simple Stupid!
