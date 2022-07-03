// In this problem we want to compute the GCD / LCM of all numbers of given ranges of the array.
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        // GCD of a single element is itself.
        t[in] = v[s];
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = __gcd(t[2 * in], t[2 * in + 1]);
    }
}
int query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return 0; 
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) / 2;
    return __gcd(query(2 * in, s, mid, qs, min(mid, qe)), query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, pos, nval);
        }
        t[in] = __gcd(t[2 * in], t[2 * in + 1]);
    }
}
int main() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    cout << query(1, 0, n - 1, 2, 3) << endl;
    update(1, 0, n - 1, 3, 8);
    cout << query(1, 0, n - 1, 0, 4);
    return 0;
}
