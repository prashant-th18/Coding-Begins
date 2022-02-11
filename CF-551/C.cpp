#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    auto oops = []() -> void { cout << ":("; };
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        string s; cin >> s;
        if(n & 1 || (s[0] == ')' || s[n - 1] == '('))
        {
            oops();
            return 0;
        }
        int cnt = 0;
        int lface = n / 2 - count(all(s), ')'), rface = n / 2 - count(all(s), '(');
        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == '?')
            {
                if(lface > 0)
                {
                    --lface; s[i] = ')';
                    cnt++;
                }
                else
                {
                    s[i] = '(';
                    --rface;
                    --cnt;
                    if((cnt < 0) || (cnt == 0 && i != 0))
                    {
                        oops(); return 0;
                    }
                }
            }
            else if(s[i] == ')')
            {
                ++cnt;
            }
            else
            {
                --cnt;
                if(cnt < 0 || (cnt == 0 && i != 0)) { oops(); return 0; }
            }
        }
        if(cnt != 0) cout << ":(";
        else 
        cout << s;
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
