#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 1;
int main() {
    int n; cin >> n;
    vector<int> occ(N, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        for(int j = 1; j * j <= t; ++j)
        {
            if(t % j == 0)
            {
                occ[j]++;
                if(j != t / j) occ[t / j]++;
            }
        }
    }
    for(int i = N - 1; i >= 1; --i)
    {
        if(occ[i] > 1)
        {
            cout << i; return 0;
        }
    }
}
