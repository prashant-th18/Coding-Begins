#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    int sz = (int)s.size();
    vector<bool> v(sz, false);
    char ch = s[0];
    for(int i = 1; i < sz; ++i)
    {
        if(s[i] > ch) v[i] = true;
        ch = min(ch, s[i]);
    }
    for(int i = 0; i < sz; ++i)
    {
        if(v[i])
        {
            cout << "Ann\n";
        }
        else
            cout << "Mike\n";
    }
    return 0;
}