#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int main()
{
    int n; cin >> n;
    vector<vector<int>> d(n, vector<int>(n, inf));
    // Input of d taken!
    // So, if there exist some edge weight between vertex "i" and "j", then we will store that value in
    // d[i][j]
    // Otherwise, d[i][j] = inf
    for(int k = 0; k < n; ++i)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                // "k" represents k-th phase.
                // Before the k-th phase, I have found the shortest distance for all pairs of i and j
                // which included {1, 2, ... , k - 1} in it's shortest path.
                if(d[i][k] < inf && d[k][j] < inf)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    // Either after including the k-th vertex, the shortest distance between "i" and "j"
                    // will remain the same, or will decrease
                    // If it decrease, that means the shortest path between vertex "i" and "j" includes
                    // "k" as well.
                }
            }
        }
    }
    // Time Complexity -> O(N^3)
    return 0;
}
