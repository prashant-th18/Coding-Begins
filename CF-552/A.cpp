#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int f = v[0] - v[1];
    int s = v[3] - f;
    int t = v[2] - f;
    cout << f << ' ' << s << ' ' << t;
    return 0;
}
