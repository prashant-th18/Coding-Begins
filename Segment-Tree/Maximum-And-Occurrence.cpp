// Finding the maximum and the number of times it appears
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
vector<int> v;
vector<pii> t; // This stores {maximum, occurrence of maximum in this segment}
pii combine(pii a, pii b) {
    if(a.first > b.first) {
        // Mtlb ye maximum mujhe a segment se hi mil skta tha
        return a;
    }
    if(a.first < b.first) {
        return b;
    }
    return pair(a.first, a.second + b.second); // Dono same maximum produce krr rhe, toh dono ke occ ko plus krdia.
}
void build(int in, int s, int e) {
    if(s == e) {
        t[in] = pair(v[s], 1); // If only one element is present, obv it is the maximum and it's occurrence is 1.
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = combine(t[in * 2], t[in * 2 + 1]);
    }
}
pii getMax(int in, int s, int e, int qs, int qe) { // qs -> query start, qe -> query end
    if(qs > qe) {
        // return something that will not change the answer
        return pair(INT_MIN, 0);
    }
    if(s == qs && e == qe) {
        return t[in];
    }
    int mid = (s + e) / 2;
    return combine(getMax(2 * in, s, mid, qs, min(qe, mid)), getMax(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = pair(nval, 1);
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, pos, nval);
        }
        t[in] = combine(t[2 * in], t[2 * in + 1]); // Recalculating the answers
    }
}
int main() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, pair(INT_MIN, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    auto p = getMax(1, 0, n - 1, 1, 4);
    cout << p.first << ' ' << p.second << '\n';
    update(1, 0, n - 1, 3, 3);
    p = getMax(1, 0, n - 1, 0, 4);
    cout << p.first << ' ' << p.second;
    return 0;
}
