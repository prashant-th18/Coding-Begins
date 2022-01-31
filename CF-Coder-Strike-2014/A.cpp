#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    string s; cin >> s;
    map<char, char> ref;
    ref['A'] = 'A';
    ref['H'] = 'H';
    ref['I'] = 'I';
    ref['M'] = 'M';
    ref['O'] = 'O';
    ref['T'] = 'T';
    ref['U'] = 'U';
    ref['V'] = 'V';
    ref['W'] = 'W';
    ref['X'] = 'X';
    ref['Y'] = 'Y';
    for (int i = 0; i < sz(s); i++) {
        if(!ref.count(s[i]))
        {
            cout << "NO"; return 0;
        }
        else
        {
            assert(true);
        }
    }
    string n = s;
    reverse(all(n));
    if(n == s)
    cout << "YES";
    else
        cout << "NO";
    return 0;
}
// -> Keep It Simple Stupid!
