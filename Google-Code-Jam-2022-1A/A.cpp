#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        cout << "Case #" << tt << ": ";
        string s; cin >> s;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while(j < s.size() && s[j] == s[i]) ++j;
            if(j == s.size() || s[j] < s[i])
            {
                res += s[i];
            }
            else
            {
                res += s[i]; res += s[i];
            }
        }
        cout << res << '\n';
    }
    return 0;
}
