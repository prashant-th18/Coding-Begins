#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> v(n + 1, 0);
    v[0] = 1; // Only 1 way to form empty subset
    vector<int> coins = {1, 2, 3, 4, 5, 6};
    for(int i = 1; i <= n; ++i)
    {
        for(auto c : coins)
        {
            if(i - c >= 0)
            {
                v[i] += v[i - c];
                v[i] %= (1000000007);
            }
        }
    }
    cout << v[n];
}
