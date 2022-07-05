// We will be given a range [l, .., r] and we want to find a continuous-subsegment in it, whose sum is maximum 
// among all other subsegments.

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
struct d {
    // In this question, each node of our tree, will hold 4 values
    int sum, // Sum of the whole segment
        pref, // Maximum prefix sum of this segment
        suff, // Maximum suffix sum of this segment
        ans; // Maximum subsegment sum of this segment
};
vector<d> t;

d combine(const d& l, const d& r) {
    // l -> left child
    // r -> right child
    d res;
    res.sum = l.sum + r.sum; // Sum of this segment is equal to sum of it's children
    res.pref = max(l.pref, l.sum + r.pref);
    // Maximum prefix?
    // -> Either Maximum prefix of the left child
    // -> Or Sum of whole left child + Maximum prefix of the right child
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    // Ans ->
    // Ya toh left child ka answer
    // Ya right child ka answer
    // Ya fir, left ka suffix and right ka prefix
    return res;
}
d make_data(int val) {
    // This function is used for leaf nodes
    d res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val); // Why 0? -> Because you can also choose empty subsegment
    return res;
}
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = make_data(v[s]);
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = combine(t[2 * in], t[2 * in + 1]);
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = make_data(nval);
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in] = combine(t[2 * in], t[2 * in + 1]);
    }
}
d query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return make_data(0); // It will not affect the answer
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) / 2;
    return combine(query(2 * in, s, mid, qs, min(qe, mid)), query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
int main() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, d(0, 0, 0, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    cout << query(1, 0, n - 1, 0, n - 1).ans << endl;
    update(1, 0, n - 1, 2, 3);
    cout << query(1, 0, n - 1, 0, n - 1).ans;
    return 0;
}
