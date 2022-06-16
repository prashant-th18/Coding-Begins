// Print all permutations of a given string
#include<bits/stdc++.h>
using namespace std;
void permute(char* s, int i)
{
    if (s[i] == '\0')
    {
        cout << s << " , ";
        return;
    }
    for (int j = i; s[j] != '\0'; ++j)
    {
        swap(s[i], s[j]);
        permute(s, i + 1);

        swap(s[i], s[j]);
    }
}
int main()
{
    char s[100];
    cin >> s;
    permute(s, 0);
    return 0;
}