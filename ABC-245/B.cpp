#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(begin(v), end(v));
    v.resize(unique(begin(v), end(v)) - begin(v));
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] != i) {
            cout << i; return 0;
        }
    }
    cout << v.size();
    return 0;
}
