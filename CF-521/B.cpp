#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int k = 0;
    for(int i = 1; i < n - 1; ++i)
    {
        if(v[i] == 0)
        {
            if(v[i - 1] == v[i + 1] && v[i - 1] == 1) {
                ++k; v[i + 1] = 0;
                ++i;
            }
        }
    }
    cout << k;
    return 0;
}
