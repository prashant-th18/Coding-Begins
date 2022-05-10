#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> c(n + m);
    for (int i = 0; i < n + m; i++) {
        cin >> c[i];
    }
    vector<int> b(m + 1);
    for(int i = m; i >= 0; --i) {
        int j = m, k = n - 1 - (m - i);
        int temp = 0;
        while(j > i) {
            temp += b[j] * a[max(0, k)];
            --j;
            ++k;
        }
        c[i] -= temp;
        c[i] /= a[k];
        b[i] = c[i];
    }
    for(auto val : b) cout << val << ' ';
    return 0;
}
