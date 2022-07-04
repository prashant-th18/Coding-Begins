#include <bits/stdc++.h>
using namespace std;
int main()
{
    string text, pattern;
    cin >> text >> pattern;
    vector<int> lps(sz(pattern), 0);
    // Computing values of LPS Array(Longest Proper Prefix which is also a suffix)
    {
        int len = 0, i = 1;
        lps[0] = 0;
        while(i < sz(pattern)) // Time Complexity -> ~O(sz(pattern))
        {
            if(pattern[i] == pattern[len])
            {
                lps[i] = len + 1;
                ++i, ++len;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
    }
    // 
    int i = 0, j = 0;
    while(i <= sz(text) - sz(pattern)) // Time Complexity -> ~O(sz(text))
    {
        if(text[i] == pattern[j])
        {
            ++i; ++j;
        }
        else
        {
            if(j != 0) j = lps[j - 1];
            else
                ++i;
        }
        if(j == sz(pattern))
        {
            cout << i - j << ' '; // Occurrence of Pattern
            // To get all occurrences 
            j = lps[j - 1]; // we assigned j to lps[j - 1], not to lps[j], because in the later case,
                            // we may miss a occurrence
        }
    }
    // Time Complexity -> O(sz(text) + sz(pattern))
    return 0;
}
// Practice ->
// https://www.codechef.com/problems/TASHIFT
