#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
vector<int> prefix_function(string s)
{
    vector<int> pi(sz(s), 0);
    // Indexing is 0 based
    pi[0] = 0;
    int n = sz(pi);
    for(int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        // Since we know that pi[i] <= pi[i - 1] + 1, so we check that first
        if(s[j] == s[i])
        {
            pi[i] = pi[i - 1] + 1;
        }
        else
        {
            while(j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }
            if(s[i] == s[j]) ++j;
            pi[i] = j;
        }
    }
    return pi;
}
int main()
{
    // Prefix Function Implementation
    string a;
    cin >> a;
    vector<int> pi = prefix_function(a);
    {
        for(int i = 0; i < sz(pi); ++i) cout << pi[i] << ' ';
        cout << endl << endl;
    }
    string text; cin >> text;
    int i = 0, j = 0; // i -> text, j -> pattern
    while(i <= (int)(text.size()))
    {
        if(text[i] == a[j])
        {
            ++i, ++j;
        }
        else
        {
            if(j == 0)
            {
                ++i;
            }
            else
            {
                j = pi[j - 1];
            }
        }
        if(j == (int)a.size())
        {
            cout << i - j << ' ';
            j = pi[j - 1];
        }
    }
    return 0;
}
