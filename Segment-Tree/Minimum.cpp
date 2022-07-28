// You are given an array of size n
// You will be given some queries of type "l r"
// You need to tell the minimum of a[l, ... , r]

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> t, v;
void build(int in, int s, int e) {
    if(s == e) {
        t[in] = v[s];
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = min(t[2 * in], t[2 * in + 1]);
    }
}
int Min(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MAX;
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) / 2;
    return min(Min(2 * in, s, mid, qs, min(qe, mid)), Min(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
int main() {
    cin >> n;
    t.assign(4 * n, 0);
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        cout << Min(1, 0, n - 1, a, b) << '\n';
    }
    return 0;
}
